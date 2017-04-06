// surface.cpp

#include <surface.h>
#include <osg\Geometry>
#include <mutex>
#include <osg/Material>

Surface::Surface() :
_xMax(3),
_yMax(_xMax),
_dx(0.2),
_dy(_dx),
_a(1),
_b(1),
_t(0.2),
_readyCalculateFlag(false),
_stopThread(false)
{
    qRegisterMetaType<osg::ref_ptr<osg::Vec3Array>>();
    
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;    //цвет

    colors->push_back(osg::Vec4(0.0f, 1.0f, 1.0f, 0.0f));

    _geomZPos->setColorArray(colors.get(), osg::Array::BIND_OVERALL);
    
    //подготовка для triangle_strip
    int numOfStrips = (2 * _yMax) / _dy;		//число "полос"
    int stripSize = 2 * (numOfStrips + 1);	//размер "полосы"
    
    for (int i = 0; i < numOfStrips; i++)
    {
        _geomZPos->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLE_STRIP, i*stripSize, stripSize));
    }

    _geomZPos->setDataVariance(osg::Object::DYNAMIC);
    _geomZPos->setUpdateCallback(_modifyCallback);

    connect(this, &Surface::CalculationIsEnded, _modifyCallback, &ModifySurface::ReceiveVertices, Qt::DirectConnection);
    connect(_modifyCallback, &ModifySurface::SendTime, this, &Surface::SetT);

    //настройка нижней части поверхности
    osg::Matrix mR;
    mR.makeRotate(osg::PI, osg::Vec3(0., 1., 0.));
    _mtZNeg->setMatrix(mR);
    _mtZNeg->addChild(_geomZPos);

    //объединение двух частей в группу
    setDataVariance(osg::Object::STATIC);
    addChild(_geomZPos);
    addChild(_mtZNeg);

    StartCalculation();
}

Surface::~Surface()
{
    StopCalculation();
}

void Surface::SetA(double a)
{
    {
        std::lock_guard<std::mutex> lgMutex(_mutex);
        _a = a;
        _readyCalculateFlag = true;
    }
    _readyCalculateCondVar.notify_one();
}

void Surface::SetB(double b)
{
    {
        std::lock_guard<std::mutex> lgMutex(_mutex);
        _b = b;
        _readyCalculateFlag = true;
    }
    _readyCalculateCondVar.notify_one();
}

void Surface::SetT(double t)
{
    {
        std::lock_guard<std::mutex> lgMutex(_mutex);
        _t = t;
        _readyCalculateFlag = true;
    }
    _readyCalculateCondVar.notify_one();
}

double Surface::findZ(double a, double b, double t, double x, double y)
{
    double powA2 = pow(a, 2);
    double powSint2 = pow(sin(t), 2);
    double powB2 = pow(b, 2);
    double denominator = powA2*powB2*powSint2;
    
    if ((a <= 0) || (b <= 0) || (t <= 0))
        return 0;
    else
        return sqrt(((powA2*powSint2*pow(x, 2) + powB2*pow(y, 2)) / denominator) + 1);
}

void Surface::StartCalculation()
{
    _readyCalculateFlag = true;
    _calculating = std::thread(&Surface::calculateThread, this);
}

void Surface::StopCalculation()
{
    if (_calculating.joinable())
    {
        _stopThread = true;
        _readyCalculateFlag = true;
        _readyCalculateCondVar.notify_all();
        _calculating.join();
    }
}

void Surface::calculateThread()      //поток расчета
{
    double a, b, t;
    while (!_stopThread)
    {
        {
            std::unique_lock<std::mutex> uLock(_mutex);
            while (!_readyCalculateFlag)
                _readyCalculateCondVar.wait(uLock);
            _readyCalculateFlag = false;
            a = _a;
            b = _b;
            t = _t;
        }
        calculate(a, b, t);
    }
}

void Surface::calculate(double a, double b, double t)	//функция расчета
{
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
    
    normals->setBinding(osg::Array::BIND_PER_VERTEX);
    
    //для нахождения векторного произведения
    osg::Vec3 edge1, edge2, edge3;	//координаты точек треугольника
    osg::Vec3 crossResult;

    double z1, z2, z3;

    //TRIANGLE_STRIP
    //вычисление 2 точек на всех последующих шагах
    for (double y = -_yMax; y <= _yMax; y += _dy)
    {
        for (double x = -_xMax; x <= _xMax + _dx; x += _dx)
        {
            z1 = findZ(a, b, t, x, y);                        
            z2 = findZ(a, b, t, x, y + _dy);
            z3 = findZ(a, b, t, x + _dx, y);	//для вычисления нормали

            edge1.set(osg::Vec3(x, y, z1));
            edge2.set(osg::Vec3(x, y + _dy, z2));
            edge3.set(osg::Vec3(x + _dx, y, z3));

            vertices->push_back(edge1);
            vertices->push_back(edge2);

            //вычисление нормали
            (crossResult = (edge2 - edge1) ^ (edge3 - edge1)).normalize();
            
            normals->push_back(crossResult);
            normals->push_back(crossResult);
        }
    }

    emit CalculationIsEnded(vertices, normals);
}
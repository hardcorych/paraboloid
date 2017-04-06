// surface.h

#pragma once

#include <osg\Node>
#include <osgViewer\Viewer>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <qobject.h>
#include <osg/MatrixTransform>
#include <modifysurface.h>

Q_DECLARE_METATYPE(osg::ref_ptr<osg::Vec3Array>)

class Surface : public QObject, public osg::Group {
    Q_OBJECT

public:
    Surface();
    ~Surface();

private:   
    double findZ(double a, double b, double t, double x, double y);
    void calculate(double a, double b, double t);		//функция расчета
    void calculateThread();								//поток расчета

private:
    const double _xMax;      //диапазон
    const double _yMax;
    const double _dx;        //шаг
    const double _dy;

	//изменяемые параметры
    double _a;
    double _b;
    double _t;		//время

    std::thread _calculating;		//для потока расчета
    std::mutex _mutex;
    std::condition_variable _readyCalculateCondVar;      
    bool _readyCalculateFlag;

    bool _stopThread;       //для закрытия потоков

    osg::ref_ptr<osg::Geometry> _geomZPos = new osg::Geometry;		//рассчитываемая поверхность
    osg::ref_ptr<osg::MatrixTransform> _mtZNeg = new osg::MatrixTransform;	//нижняя часть поверхности

    osg::ref_ptr<ModifySurface> _modifyCallback = new ModifySurface;	

signals:
    void CalculationIsEnded(osg::ref_ptr<osg::Vec3Array> _vertices, osg::ref_ptr<osg::Vec3Array> _normals);

public slots:
    void SetA(double _a);
    void SetB(double _b);
    void SetT(double _t);
    void StartCalculation();
    void StopCalculation();
};

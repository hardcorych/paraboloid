// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qslider.h>
#include <qlineedit.h>
#include <surface.h>
#include <thread>
#include <QDebug>
#include <osg/MatrixTransform>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow),
_isRenderStopped(false)
{
    ui->setupUi(this);

    //настройка слайдеров
    connect(ui->hSliderA, &QSlider::sliderPressed, this, &MainWindow::onHSliderASliderPressed);
    connect(ui->hSliderB, &QSlider::sliderPressed, this, &MainWindow::onHSliderBSliderPressed);

    connect(ui->hSliderA, &QSlider::sliderReleased, this, &MainWindow::onHSliderASliderReleased);
    connect(ui->hSliderB, &QSlider::sliderReleased, this, &MainWindow::onHSliderBSliderReleased);

	ui->hSliderA->setMaximum(200);
	ui->hSliderB->setMaximum(200);

    setSliderCenter(ui->hSliderA);
    setSliderCenter(ui->hSliderB);

    ui->hSliderA->setPageStep(0);
    ui->hSliderB->setPageStep(0);

    ui->hSliderA->setSingleStep(0);
    ui->hSliderB->setSingleStep(0);

    //настройка спинбоксов
    connect(ui->dSpinBoxA, 
        static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
        this, &MainWindow::SendA);
    connect(ui->dSpinBoxB,
        static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
        this, &MainWindow::SendB);

    ui->dSpinBoxA->setRange(0.01, 200);
    ui->dSpinBoxB->setRange(0.01, 200);

    ui->dSpinBoxA->setValue(1);
    ui->dSpinBoxB->setValue(1);

    //настройка таймеров
    _timerA = new QTimer(this);
    _timerB = new QTimer(this);

    _timerA->setInterval(100);
    _timerB->setInterval(100);

    connect(_timerA, &QTimer::timeout, this, &MainWindow::timerAUpdate);
    connect(_timerB, &QTimer::timeout, this, &MainWindow::timerBUpdate);

	//поток viewer
    _renderThread = std::thread(&MainWindow::renderScene, this);
}

MainWindow::~MainWindow()
{
    if (_renderThread.joinable())
    {
        _isRenderStopped = true;
        _renderThread.join();
    }
}

void MainWindow::quitAppFromRenderThread()
{
    emit QuitAppToMain();
}

int MainWindow::renderScene()
{
    osgViewer::Viewer viewer;

    osg::ref_ptr<Surface> surface = new Surface;
    osg::ref_ptr<Surface> surface2 = new Surface;
    osg::ref_ptr<Surface> surface3 = new Surface;

    //настройка окна
    int xViewer = 100;
    int yViewer = 100;
    int wViewer = 640;
    int hViewer = 480;

    viewer.setUpViewInWindow(xViewer, yViewer, wViewer, hViewer);

    connect(this, &MainWindow::SendA, surface, &Surface::SetA, Qt::DirectConnection);
    connect(this, &MainWindow::SendB, surface, &Surface::SetB, Qt::DirectConnection);
    connect(this, &MainWindow::SendA, surface2, &Surface::SetA, Qt::DirectConnection);
    connect(this, &MainWindow::SendB, surface2, &Surface::SetB, Qt::DirectConnection);
    connect(this, &MainWindow::SendA, surface3, &Surface::SetA, Qt::DirectConnection);
    connect(this, &MainWindow::SendB, surface3, &Surface::SetB, Qt::DirectConnection);

    //настройка камеры
    //viewer.getCamera()->setClearColor(osg::Vec4(1., 1., 1., 1.));
    
	//формирование группы объектов
    osg::ref_ptr<osg::MatrixTransform> mTransform2 = new osg::MatrixTransform;
    osg::Matrix mT;
    mT.makeTranslate(-6., 0, 0.);
    mTransform2->setMatrix(mT);
    mTransform2->addChild(surface2);
    
    osg::ref_ptr<osg::MatrixTransform> mTransform3 = new osg::MatrixTransform;
    mT.makeTranslate(6., 0, 0.);
    mTransform3->setMatrix(mT);
    mTransform3->addChild(surface3);

    osg::ref_ptr<osg::Group> group = new osg::Group;

    group->addChild(surface);
    group->addChild(mTransform2);
    group->addChild(mTransform3);

	//установка позиции камеры
	osg::Vec3 eye(-50, -35, 0);
	osg::Vec3 center(0, 0, 0);
	osg::Vec3 up(0, 0, 1);

	viewer.setCameraManipulator(new osgGA::TrackballManipulator);
	viewer.getCameraManipulator()->setHomePosition(eye, center, up, false);

	//статистика
	osg::ref_ptr<osgViewer::StatsHandler> statsHandler = new osgViewer::StatsHandler;
	viewer.addEventHandler(statsHandler);

    viewer.setSceneData(group);

    //viewer.setRunMaxFrameRate(1);

	while ((!_isRenderStopped) && (!viewer.done()))
		viewer.frame();
	
	//viewer.run();
    
    quitAppFromRenderThread();		//завершение программмы
    
    return 0;
}

void MainWindow::setSliderCenter(QSlider* slider)
{
    slider->setValue(slider->maximum() / 2);
}

void MainWindow::onHSliderASliderPressed()
{
    _timerA->start();
}

void MainWindow::onHSliderBSliderPressed()
{
    _timerB->start();
}

void MainWindow::onHSliderASliderReleased()
{
    _timerA->stop();
    setSliderCenter(ui->hSliderA);
}

void MainWindow::onHSliderBSliderReleased()
{
    _timerB->stop();
    setSliderCenter(ui->hSliderB);
}

void MainWindow::timerAUpdate()
{
    //изменение значения А
    surfaceCoeffSet(ui->dSpinBoxA, ui->hSliderA);
}

void MainWindow::timerBUpdate()
{
    //изменение значения B
    surfaceCoeffSet(ui->dSpinBoxB, ui->hSliderB);
}

void MainWindow::surfaceCoeffSet(QDoubleSpinBox* doubleSpinBox, QSlider* slider)
{
    double valueSpinBox = doubleSpinBox->value();

    double sliderMax = slider->maximum();
    double sliderCenter = sliderMax / 2;
    double sliderValue = slider->sliderPosition() - sliderCenter;

    double acceleration = abs((sliderValue / sliderMax) / sliderCenter);  //коэффициент ускорения изменения значений

    double value = valueSpinBox + acceleration*sliderValue;

    doubleSpinBox->setValue(value);
}
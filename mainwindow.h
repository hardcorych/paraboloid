// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qslider.h>
#include <qlineedit.h>
#include <thread>
#include <qspinbox.h>
#include <qtimer.h>
#include <memory>
#include <condition_variable>
#include <surface.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    private slots:
    void timerAUpdate();
    void timerBUpdate();

    void onHSliderASliderPressed();
    void onHSliderBSliderPressed();

    void onHSliderASliderReleased();
    void onHSliderBSliderReleased();

    void quitAppFromRenderThread();

signals:
    void StartCalculation();
    void SendA(double a);
    void SendB(double b);
    void StopCalculation();
    void QuitAppToMain();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::thread _renderThread;
    bool _isRenderStopped;
    QTimer* _timerA;
    QTimer* _timerB;

    void setSliderCenter(QSlider* slider);
    int renderScene();
    void surfaceCoeffSet(QDoubleSpinBox* doubleSpinBox, QSlider* slider);
};

#endif // MAINWINDOW_H


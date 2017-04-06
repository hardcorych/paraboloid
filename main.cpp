// main.cpp

#include "mainwindow.h"
#include <QApplication>

#include <surface.h>

#include <thread>
#include <mutex>
#include <condition_variable>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QObject::connect(&w, &MainWindow::QuitAppToMain, &a, &QApplication::quit);

    w.show();
    
    return a.exec();
}
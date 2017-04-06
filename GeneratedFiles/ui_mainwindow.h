/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelA;
    QLabel *labelB;
    QSlider *hSliderA;
    QSlider *hSliderB;
    QDoubleSpinBox *dSpinBoxA;
    QDoubleSpinBox *dSpinBoxB;
    QLabel *labelPlusA;
    QLabel *labelPlusB;
    QLabel *labelMinusA;
    QLabel *labelMinusB;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(384, 221);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelA = new QLabel(centralWidget);
        labelA->setObjectName(QStringLiteral("labelA"));
        labelA->setGeometry(QRect(40, 60, 31, 16));
        labelA->setAlignment(Qt::AlignCenter);
        labelB = new QLabel(centralWidget);
        labelB->setObjectName(QStringLiteral("labelB"));
        labelB->setGeometry(QRect(40, 100, 31, 16));
        labelB->setAlignment(Qt::AlignCenter);
        hSliderA = new QSlider(centralWidget);
        hSliderA->setObjectName(QStringLiteral("hSliderA"));
        hSliderA->setGeometry(QRect(160, 60, 160, 22));
        hSliderA->setOrientation(Qt::Horizontal);
        hSliderB = new QSlider(centralWidget);
        hSliderB->setObjectName(QStringLiteral("hSliderB"));
        hSliderB->setGeometry(QRect(160, 100, 160, 22));
        hSliderB->setOrientation(Qt::Horizontal);
        dSpinBoxA = new QDoubleSpinBox(centralWidget);
        dSpinBoxA->setObjectName(QStringLiteral("dSpinBoxA"));
        dSpinBoxA->setGeometry(QRect(70, 60, 62, 22));
        dSpinBoxA->setWrapping(false);
        dSpinBoxA->setAlignment(Qt::AlignCenter);
        dSpinBoxA->setReadOnly(true);
        dSpinBoxA->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSpinBoxA->setKeyboardTracking(false);
        dSpinBoxA->setMinimum(0);
        dSpinBoxA->setValue(1);
        dSpinBoxB = new QDoubleSpinBox(centralWidget);
        dSpinBoxB->setObjectName(QStringLiteral("dSpinBoxB"));
        dSpinBoxB->setGeometry(QRect(70, 100, 62, 22));
        dSpinBoxB->setAlignment(Qt::AlignCenter);
        dSpinBoxB->setReadOnly(true);
        dSpinBoxB->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dSpinBoxB->setKeyboardTracking(false);
        dSpinBoxB->setValue(1);
        labelPlusA = new QLabel(centralWidget);
        labelPlusA->setObjectName(QStringLiteral("labelPlusA"));
        labelPlusA->setGeometry(QRect(320, 60, 20, 16));
        labelPlusA->setAlignment(Qt::AlignCenter);
        labelPlusB = new QLabel(centralWidget);
        labelPlusB->setObjectName(QStringLiteral("labelPlusB"));
        labelPlusB->setGeometry(QRect(320, 100, 21, 16));
        labelPlusB->setAlignment(Qt::AlignCenter);
        labelMinusA = new QLabel(centralWidget);
        labelMinusA->setObjectName(QStringLiteral("labelMinusA"));
        labelMinusA->setGeometry(QRect(140, 60, 20, 16));
        labelMinusA->setAlignment(Qt::AlignCenter);
        labelMinusB = new QLabel(centralWidget);
        labelMinusB->setObjectName(QStringLiteral("labelMinusB"));
        labelMinusB->setGeometry(QRect(140, 100, 20, 16));
        labelMinusB->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 384, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GUI", Q_NULLPTR));
        labelA->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        labelB->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        labelPlusA->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        labelPlusB->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        labelMinusA->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        labelMinusB->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

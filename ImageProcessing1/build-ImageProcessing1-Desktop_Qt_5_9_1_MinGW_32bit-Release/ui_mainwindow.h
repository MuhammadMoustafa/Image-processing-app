/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *lbl_imageInverted;
    QLabel *lbl_imageThresholded;
    QLabel *lbl_image;
    QGridLayout *gridLayout_3;
    QCustomPlot *widget_cdf;
    QCustomPlot *widget_hist;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_browse;
    QPushButton *btn_plot;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_threshold;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QRadioButton *rdbtn_negation;
    QRadioButton *rdbtn_normalization;
    QRadioButton *rdbtn_histequ;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1154, 862);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setContentsMargins(10, -1, 10, -1);
        lbl_imageInverted = new QLabel(centralWidget);
        lbl_imageInverted->setObjectName(QStringLiteral("lbl_imageInverted"));

        gridLayout->addWidget(lbl_imageInverted, 0, 1, 1, 1);

        lbl_imageThresholded = new QLabel(centralWidget);
        lbl_imageThresholded->setObjectName(QStringLiteral("lbl_imageThresholded"));

        gridLayout->addWidget(lbl_imageThresholded, 0, 2, 1, 1);

        lbl_image = new QLabel(centralWidget);
        lbl_image->setObjectName(QStringLiteral("lbl_image"));

        gridLayout->addWidget(lbl_image, 0, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        widget_cdf = new QCustomPlot(centralWidget);
        widget_cdf->setObjectName(QStringLiteral("widget_cdf"));

        gridLayout_3->addWidget(widget_cdf, 0, 1, 1, 1);

        widget_hist = new QCustomPlot(centralWidget);
        widget_hist->setObjectName(QStringLiteral("widget_hist"));

        gridLayout_3->addWidget(widget_hist, 0, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        btn_browse = new QPushButton(centralWidget);
        btn_browse->setObjectName(QStringLiteral("btn_browse"));

        verticalLayout_3->addWidget(btn_browse);

        btn_plot = new QPushButton(centralWidget);
        btn_plot->setObjectName(QStringLiteral("btn_plot"));

        verticalLayout_3->addWidget(btn_plot);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(40);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 20);
        lbl_threshold = new QLabel(centralWidget);
        lbl_threshold->setObjectName(QStringLiteral("lbl_threshold"));
        QFont font;
        font.setPointSize(21);
        font.setBold(true);
        font.setWeight(75);
        lbl_threshold->setFont(font);
        lbl_threshold->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbl_threshold);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rdbtn_negation = new QRadioButton(centralWidget);
        rdbtn_negation->setObjectName(QStringLiteral("rdbtn_negation"));
        QFont font1;
        font1.setKerning(true);
        rdbtn_negation->setFont(font1);

        verticalLayout->addWidget(rdbtn_negation);

        rdbtn_normalization = new QRadioButton(centralWidget);
        rdbtn_normalization->setObjectName(QStringLiteral("rdbtn_normalization"));

        verticalLayout->addWidget(rdbtn_normalization);

        rdbtn_histequ = new QRadioButton(centralWidget);
        rdbtn_histequ->setObjectName(QStringLiteral("rdbtn_histequ"));

        verticalLayout->addWidget(rdbtn_histequ);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 300);
        horizontalLayout->setStretch(1, 800);
        horizontalLayout->setStretch(2, 300);

        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1154, 25));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lbl_imageInverted->setText(QString());
        lbl_imageThresholded->setText(QString());
        lbl_image->setText(QString());
        btn_browse->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        btn_plot->setText(QApplication::translate("MainWindow", "Plot Graphs", Q_NULLPTR));
        lbl_threshold->setText(QApplication::translate("MainWindow", "Threshold", Q_NULLPTR));
        rdbtn_negation->setText(QApplication::translate("MainWindow", "Negat&ion", Q_NULLPTR));
        rdbtn_normalization->setText(QApplication::translate("MainWindow", "Norma&lization", Q_NULLPTR));
        rdbtn_histequ->setText(QApplication::translate("MainWindow", "Histogram &Equalization", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#-------------------------------------------------
#
# Project created by QtCreator 2017-08-13T10:37:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ImageProcessing1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        qcustomplot.cpp

HEADERS += \
        mainwindow.h \
        qcustomplot.h

FORMS += \
        mainwindow.ui

#INCLUDEPATH += "/usr/local/include/"

#LIBS += -L"/usr/local/lib"
#LIBS += -lopencv_highgui
#LIBS += -lopencv_core
#LIBS += -lopencv_imgproc
#LIBS += -lopencv_imgcodecs

INCLUDEPATH += E:\Programs\Windows\sPrograms\opencv\opencvsource\build\include
#LIBS += -L"/usr/local/lib"
#LIBS += -lopencv_highgui
#LIBS += -lopencv_core
#LIBS += -lopencv_imgproc
#LIBS += -lopencv_imgcodecs


LIBS += E:\Programs\Windows\sPrograms\opencv\opencvrelease\bin\libopencv_core330.dll
LIBS += E:\Programs\Windows\sPrograms\opencv\opencvrelease\bin\libopencv_highgui330.dll
LIBS += E:\Programs\Windows\sPrograms\opencv\opencvrelease\bin\libopencv_imgcodecs330.dll
LIBS += E:\Programs\Windows\sPrograms\opencv\opencvrelease\bin\libopencv_imgproc330.dll
LIBS += E:\Programs\Windows\sPrograms\opencv\opencvrelease\bin\libopencv_features2d330.dll
LIBS += E:\Programs\Windows\sPrograms\opencv\opencvrelease\bin\libopencv_calib3d330.dll

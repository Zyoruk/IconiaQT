#-------------------------------------------------
#
# Project created by QtCreator 2014-09-27T21:56:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT-Iconia
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    detector.cpp

HEADERS  += mainwindow.h \
    detector.h \
    Graph/graph.h \
    Graph/graphNode/graphnode.h \
    SimpleList/SimpleList.h \
    SimpleList/Node/SimpleListNode.h \
    stack/stack.h \
    stack/stackNode.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree

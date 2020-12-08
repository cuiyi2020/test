#-------------------------------------------------
#
# Project created by QtCreator 2020-11-25T14:47:48
#
#-------------------------------------------------

QT       += core gui qml quickwidgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rockman
TEMPLATE = app

CONFIG += c++11 qml_debug

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    rwidget.cpp \
    task_report/repitem.cpp \
    task_report/report.cpp \
    task_report/abstractlistmodel.cpp \
    task_report/dataobject.cpp \
    login/rlogin.cpp \
    login/rxml.cpp \
    login/sha.cpp

HEADERS += \
        widget.h \
    rwidget.h \
    task_report/repitem.h \
    task_report/repitembase.h \
    task_report/report.h \
    task_report/abstractlistmodel.h \
    task_report/dataobject.h \
    login/rlogin.h \
    login/rxml.h \
    practice.h \
    login/sha.h \
    login/accountlist.h

FORMS += \
        widget.ui

INCLUDEPATH += /opt/ros/melodic/include
DEPENDPATH += /opt/ros/melodic/include

INCLUDEPATH += /home/roborock/RoboScrub_Nav/devel/include

LIBS += -L /usr/lib/x86_64-linux-gnu -lboost_system -lboost_thread

LIBS +=-L/opt/ros/melodic/lib  -lactionlib -lroscpp -lrospack -lpthread -lrosconsole -lrosconsole_log4cxx -lrosconsole_backend_interface -lxmlrpcpp -lroscpp_serialization -lrostime  -lcpp_common  -lroslib -ltf  -lyaml-cpp -lkdl_conversions

RESOURCES += \
    resource_qml/resource_qml.qrc \
    resource/png.qrc


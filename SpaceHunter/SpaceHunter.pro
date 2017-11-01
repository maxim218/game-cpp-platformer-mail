#-------------------------------------------------
#
# Project created by QtCreator 2017-10-28T18:00:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceHunter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    render.cpp \
    worldbuilder.cpp \
    objectscreator.cpp \
    movementcontroller.cpp \
    matrixworker.cpp \
    gamemanager.cpp \
    styleworker.cpp \
    positionmanager.cpp

HEADERS  += mainwindow.h \
    render.h \
    worldbuilder.h \
    objectscreator.h \
    physicalobject.h \
    movementcontroller.h \
    matrixworker.h \
    gamemanager.h \
    styleworker.h \
    positionmanager.h \
    maploader.h \
    thingloader.h \
    fileloader.h \
    factoryoffileloaders.h

FORMS    += mainwindow.ui

RESOURCES += \
    resourses.qrc

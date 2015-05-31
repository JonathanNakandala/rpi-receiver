#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T21:09:14
#
#-------------------------------------------------

QT       += core
QT += network widgets
//QT       -= gui

TARGET = rpi-receiver
CONFIG   += console
CONFIG   += app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    receiver.cpp

HEADERS += \
    receiver.h

INSTALLS += target

#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T21:09:14
#
#-------------------------------------------------

QT       += core
QT += network widgets
QT       -= gui

TARGET = rpi-receiver
CONFIG   += console
CONFIG   += app_bundle
CONFIG += static
CONFIG += staticlib
TEMPLATE = app


SOURCES += main.cpp \
    receiver.cpp \
    transmitter.cpp \
    control.cpp

HEADERS += \
    receiver.h \
    transmitter.h \
    control.h \
    globalVar.h


target.path = /home/pi/cop
INSTALLS += target

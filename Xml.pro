#-------------------------------------------------
#
# Project created by QtCreator 2014-09-11T16:06:52
#
#-------------------------------------------------

QT       += core xml testlib

QT       -= gui

TARGET = Xml
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    parser.cpp

HEADERS += \
    all.h \
    parser.h
LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui

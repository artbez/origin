#-------------------------------------------------
#
# Project created by QtCreator 2014-05-21T11:25:07
#
#-------------------------------------------------

QT += testlib
CONFIG += c++11

QT       += core

QT       -= gui

TARGET = zachet
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    stringcomporator.cpp

HEADERS += \
    comporatorinterface.h \
    stringcomporator.h \
    bublesort.h \
    intcomporator.h \
    tests.h

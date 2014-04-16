#-------------------------------------------------
#
# Project created by QtCreator 2014-04-15T21:56:27
#
#-------------------------------------------------
QT += testlib
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    listelement.cpp \
    linkedstack.cpp \
    stackonarray.cpp \
    calculateByOpz.cpp \
    toOpz.cpp

HEADERS += \
    stack.h \
    listelement.h \
    linkedstack.h \
    stackonarray.h \
    calculateByOpz.h \
    toOpz.h \
    testLinkedStack.h \
    testStackOnArray.h \
    testOpz.h

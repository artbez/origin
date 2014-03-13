#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T00:02:33
#
#-------------------------------------------------

QMAKE_CXXFLAGS += -std=c++0x

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    toOpz.cpp \
    calculateByOpz.cpp \
    linkedstack.cpp \
    listelement.cpp

HEADERS  += mainwindow.h \
    toOpz.h \
    stack.h \
    listelement.h \
    linkedstack.h \
    calculateByOpz.h

FORMS    += mainwindow.ui

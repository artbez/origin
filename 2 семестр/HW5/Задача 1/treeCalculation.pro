#-------------------------------------------------
#
# Project created by QtCreator 2014-03-29T21:46:52
#
#-------------------------------------------------

QT += testlib
CONFIG += c++11
QT       += core

QT       -= gui

TARGET = treeCalculation
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tree.cpp \
    sign.cpp

HEADERS += \
    treeinterface.h \
    tree.h \
    sign.h

OTHER_FILES += \
    file.txt

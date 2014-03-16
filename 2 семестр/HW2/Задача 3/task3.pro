QT += testlib
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp \
    bublesorting.cpp

HEADERS += \
    sorting.h \
    bublesorting.h \
    bublesorttest.h


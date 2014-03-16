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
    bublesorting.cpp \
    quicksorting.cpp

HEADERS += \
    sorting.h \
    bublesorting.h \
    quicksorting.h \
    quicksorttest.h \
    bublesorttest.h


#QT += testlib
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle

SOURCES += main.cpp \
    consolewriter.cpp \
    filewriter.cpp \
    writer.cpp

HEADERS += \
    consolewriter.h \
    filewriter.h \
    interfacewriter.h \
    writer.h \
    mainTests.h


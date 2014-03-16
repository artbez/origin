#-------------------------------------------------
#
# Project created by QtCreator 2014-02-20T12:19:29
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
    linkedlist.cpp \
    listonarray.cpp

HEADERS += \
    list.h \
    listelement.h \
    linkedlist.h \
    listonarray.h \
    testLinkedList.h \
    testListOnArray.h

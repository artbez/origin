#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T21:41:38
#
#-------------------------------------------------
QT += testlib
CONFIG += c++11
QT       += core

QT       -= gui

TARGET = ListWithErrors
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    listelement.cpp \
    linkedlist.cpp \
    uniquelist.cpp

HEADERS += \
    listelement.h \
    list.h \
    linkedlist.h \
    uniquelist.h \
    testuniquelist.h \
    myerror.h

#-------------------------------------------------
#
# Project created by QtCreator 2014-03-23T02:17:48
#
#-------------------------------------------------

QT += testlib
CONFIG += c++11
QT       += core

QT       -= gui

TARGET = hashTable
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myhashtable.cpp \
    listelement.cpp \
    linkedlist.cpp \
    hashfunction.cpp

HEADERS += \
    myhashtable.h \
    listelement.h \
    list.h \
    linkedlisttest.h \
    linkedlist.h \
    hashtabletest.h \
    hashtableinterface.h \
    hashfunction.h

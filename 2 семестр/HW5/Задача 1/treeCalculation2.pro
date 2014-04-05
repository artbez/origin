#-------------------------------------------------
#
# Project created by QtCreator 2014-04-05T19:12:08
#
#-------------------------------------------------

QT += testlib
CONFIG += c++11
QT       += core

QT       -= gui

TARGET = treeCalculation2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tree.cpp \
    node.cpp \
    dev.cpp \
    mul.cpp \
    neg.cpp \
    num.cpp \
    sum.cpp

HEADERS += \
    node.h \
    sum.h \
    neg.h \
    mul.h \
    dev.h \
    tree.h \
    num.h \
    testingtree.h

OTHER_FILES += \
    file.txt

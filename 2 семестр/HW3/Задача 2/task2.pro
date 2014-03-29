#-------------------------------------------------
#
# Project created by QtCreator 2014-03-09T18:40:04
#
#-------------------------------------------------
QT += testlib
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    calculatortest.h

FORMS    += mainwindow.ui

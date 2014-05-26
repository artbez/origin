#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T18:16:19
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tic-tac-toe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    dialog.cpp \
    server.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    game.h \
    dialog.h \
    server.h \
    client.h \
    gamestates.h

FORMS    += mainwindow.ui \
    dialog.ui \
    server.ui \
    client.ui

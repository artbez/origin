#pragma once

#include "ui_mainwindow.h"
#include "game.h"
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVector>
#include <QSignalMapper>
#include <QGridLayout>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void enterWinner(QString msg);

private slots:
    void newGame();
    void wasClicked(int index);

private:
    Game *currentGame;
    QSignalMapper *qsm;
    Ui::MainWindow *ui;
    int gSize;
    QVector<QPushButton*> buttons;
};

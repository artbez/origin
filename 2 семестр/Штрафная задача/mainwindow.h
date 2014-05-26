#pragma once

#include "ui_mainwindow.h"
#include "game.h"
#include "dialog.h"
#include "server.h"
#include "client.h"
#include "gamestates.h"
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
    void sendMessage(int index);
    /// everythigs are prepeared for game
    void enable(int index);
    /// start to play by network
    void choiceMenu();
    /// start to play offline
    void gameOffline();
    void wasClicked(int index);
    void catchNewInfo(int index);
    void newConfig(int first, int second);
    void throwNewConfig();
    void crashed();

private:
    void deleteNetworkStaff();
    void getWinner(int curState, int winner);
    void newGame();
    Ui::MainWindow *ui;
    GameStates gameStates;
    Dialog * dialog = nullptr;
    Server * server = nullptr;
    Client * client = nullptr;
    Game *currentGame;
    QSignalMapper *qsm;
    int gSize;
    QVector<QPushButton*> buttons;
};

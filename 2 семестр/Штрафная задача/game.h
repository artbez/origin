#pragma once

#include <QVector>
#include <QString>
#include <QObject>
#include "gamestates.h"

class Game : public QObject
{
Q_OBJECT

public:
    Game(): numberToWin(3), currentPlayer(0), gameStates(offline) {}
    /// gets number of how many cells need to be crossed for win
    void setNumberToWin(int newNumberToWin)
    {
        numberToWin = newNumberToWin;
    }
    /// inicializes size*size field
    void setCells(int size);
    /// returns string which need to be written on a clicked button
    QString getNeededString(int index);
    /// checks situation(who win or is it a draw or it's nothing) and returns result
    int checkSituation(int index);
    int getCurrentPlayer();
    /// change cell with current index
    void changeSells(int index);   
    /// set state of current game
    void setGameStates(GameStates gameStates);

signals: 
    void sendMessage(int index);

private:
    /// all cells states
    enum States { nothing, cross, zero };
    /// checks is there a possibility to do next move
    bool noNothing();
    QString stringFromState(States state);
    /// checks all possible vertical and horizontal combinations
    bool checkLines(int index);
    /// checks all possible diagonal combinations
    bool checkDiagonals(int index);
    void nextPlayer();
    int numberToWin;
    int numberOfCellsInLine;
    int currentPlayer;
    QVector<States> cells;
    GameStates gameStates;
};

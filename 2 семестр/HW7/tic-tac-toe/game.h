#pragma once

#include <QVector>
#include <QString>

class Game
{

public:
    Game();
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

private:
    /// all cells states
    enum states { Nothing, Cross, Zero };
    /// checks is there a possibility to do next move
    bool noNothing();
    QString stringFromState(enum states state);
    /// checks all possible vertical and horizontal combinations
    bool checkLines(int index);
    /// checks all possible diagonal combinations
    bool checkDiagonals(int index);
    void nextPlayer();
    int numberToWin;
    int numberOfCellsInLine;
    int currentPlayer;
    QVector<states> cells;
};

#include "game.h"

void Game::nextPlayer()
{
    currentPlayer = 1 - currentPlayer;
}

void Game::setCells(int size)
{
    if (!cells.isEmpty())
        cells.clear();
    for (int i = 0; i < size * size; ++i)
        cells.append(nothing);
    numberOfCellsInLine = size;
}

QString Game::getNeededString(int index)
{
    QString result = "";
    switch(currentPlayer)
    {
    case 0:
        cells[index] = cross;
        result = "X";
        break;
    case 1:
        cells[index] = zero;
        result = "0";
        break;
    }
    if (gameStates != offline)
        emit sendMessage(index);
    return result;
}

bool Game::noNothing()
{
    for (int i = 0; i < numberOfCellsInLine * numberOfCellsInLine; ++i)
        if (cells[i] == nothing)
            return false;
    return true;
}

QString Game::stringFromState(States state)
{
    QString result = "";
    switch(state)
    {
    case nothing:
        result = " ";
        break;
    case cross:
        result = "X";
        break;
    case zero:
        result = "0";
        break;
    }

    return result;
}

int Game::checkSituation(int index)
{
    if (noNothing())
        return 0;
    if (!checkLines(index) && !checkDiagonals(index))
    {
        if (gameStates == offline)
            nextPlayer();
        return -1;
    }
    return currentPlayer + 1;
}

int Game::getCurrentPlayer()
{
    return currentPlayer;
}

void Game::changeSells(int index)
{
    switch(1 - currentPlayer)
    {
    case 0:
        cells[index] = cross;
        break;
    case 1:
        cells[index] = zero;
        break;
    }
}

void Game::setGameStates(GameStates gameStates)
{
    switch(gameStates)
    {
    case serverGame:
    case offline:
        currentPlayer = 0;
        break;
    case clientGame:
        currentPlayer = 1;
        break;
    }
    this->gameStates = gameStates;
}

bool Game::checkLines(int index)
{
    int firstIndex = index % numberOfCellsInLine;
    int secondIndex = index / numberOfCellsInLine;
    bool res = true;
    States current = cells[index];

    /// checks all possible vertical combinations
    for (int i = 0; i < numberToWin; ++i)
    {
        res = true;
        if ((firstIndex - numberToWin + i + 1 < 0) || (firstIndex + i) >= numberOfCellsInLine)
            continue;
        for (int j = - numberToWin + i + 1; j < i + 1; ++j)
        {
            res = res && cells[firstIndex + j + secondIndex * numberOfCellsInLine] == current;
        }
        if (res)
            return true;
    }

    /// checks all possible horizontal combinations
    for (int i = 0; i < numberToWin; ++i)
    {
        res = true;
        if ((secondIndex - numberToWin + i + 1 < 0) || (secondIndex + i) >= numberOfCellsInLine)
            continue;
        for (int j = - numberToWin + i + 1; j < i + 1; ++j)
        {
            res = res && cells[firstIndex + (secondIndex + j) * numberOfCellsInLine] == current;
        }
        if (res)
            return true;
    }

    return false;
}

bool Game::checkDiagonals(int index)
{
    bool res = true;
    States current = cells[index];

    int firstIndex = index % numberOfCellsInLine;
    int secondIndex = index / numberOfCellsInLine;

    /// checks all possible diagonal combinations from left to right
    for (int i = 0; i < numberToWin; ++i)
    {
        res = true;
        if ((firstIndex - numberToWin + i + 1 < 0) || (firstIndex + i) >= numberOfCellsInLine ||
               (secondIndex - numberToWin + i + 1 < 0) || (secondIndex + i) >= numberOfCellsInLine)
            continue;
        for (int j = - numberToWin + i + 1; j < i + 1; ++j)
        {
            res = res && cells[firstIndex + j + (secondIndex + j) * numberOfCellsInLine] == current;
        }
        if (res)
            return true;
    }

    /// checks all possible diagonal combinations from right to left
    for (int i = 0; i < numberToWin; ++i)
    {
        res = true;
        if ((firstIndex - numberToWin + i + 1 < 0) || (firstIndex + i) >= numberOfCellsInLine ||
                (secondIndex - i < 0) || (secondIndex + numberToWin - i - 1) >= numberOfCellsInLine)
            continue;
        for (int j = - numberToWin + i + 1; j < i + 1; ++j)
        {
            res = res && cells[firstIndex + j + (secondIndex - j) * numberOfCellsInLine] == current;
        }
        if (res)
            return true;
    }
    return false;
}

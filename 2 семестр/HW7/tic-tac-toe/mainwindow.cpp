#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentGame = new Game();
    ui->numberToWin->setValue(3);
    ui->sizeOfField->setValue(3);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(newGame()));
    newGame();
}

MainWindow::~MainWindow()
{
    delete currentGame;
    delete qsm;
    for (int i = 0; i < gSize * gSize; ++i)
        delete ui->buttonsLayout->itemAtPosition(i % gSize, i / gSize)->widget();
    buttons.clear();
    delete ui;
}

void MainWindow::newGame()
{
    currentGame->setNumberToWin(ui->numberToWin->value());
    if (!buttons.empty())
    {
        for (int i = 0; i < gSize * gSize; ++i)
            delete ui->buttonsLayout->itemAtPosition(i % gSize, i / gSize)->widget();
        delete qsm;

        buttons.clear();
    }
    gSize = ui->sizeOfField->value();
    qsm = new QSignalMapper(this);

    QGridLayout *gridLayout = ui->buttonsLayout;
    for (int i = 0; i < gSize * gSize; ++i)
    {
        QPushButton *tmp = new QPushButton(" ", this);
        buttons.append(tmp);
        tmp->setMinimumSize(30, 30);
        tmp->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        connect(tmp, SIGNAL(clicked()), qsm, SLOT(map()));
        qsm->setMapping(tmp, i);
        gridLayout->addWidget(tmp, i % gSize, i / gSize);
    }
    currentGame->setCells(gSize);
    connect(qsm, SIGNAL(mapped(int)), this, SLOT(wasClicked(int)));
}

void MainWindow::wasClicked(int index)
{
    if (buttons[index]->text() != " ")
        return;
    QString newValue = currentGame->getNeededString(index);
    buttons[index]->setText(newValue);
    int curState = currentGame->checkSituation(index);
    switch(curState)
    {
    case 0:
        enterWinner("Draw");
        break;
    case 1: case 2:
        enterWinner("The Winner is player " + QString::number(curState));
        break;
    }
}

void MainWindow::enterWinner(QString msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
    newGame();
}


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameStates(offline)
{
    ui->setupUi(this);
    currentGame = new Game();
    ui->numberToWin->setValue(3);
    ui->sizeOfField->setValue(3);
    server = new Server();
    client = new Client();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(gameOffline()));
    connect(ui->onlineGameButton, SIGNAL(clicked()), this, SLOT(choiceMenu()));
    connect(currentGame, SIGNAL(sendMessage(int)), this, SLOT(sendMessage(int)));
    setWindowTitle("Игра оффлайн");
    newGame();
}

MainWindow::~MainWindow()
{
    delete currentGame;
    delete qsm;
    for (int i = 0; i < gSize * gSize; ++i)
        delete ui->buttonsLayout->itemAtPosition(i % gSize, i / gSize)->widget();
    buttons.clear();
    deleteNetworkStaff();
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

void MainWindow::gameOffline()
{
    sendMessage(-1);
    crashed();
}

void MainWindow::wasClicked(int index)
{
    if (buttons[index]->text() != " ")
        return;
    QString newValue = currentGame->getNeededString(index);
    buttons[index]->setText(newValue);
    int curState = currentGame->checkSituation(index);
    if (gameStates != offline)
    {
        setWindowTitle("Ожидание хода соперника");
        setEnabled(false);
    }
    getWinner(curState, curState);
}

void MainWindow::catchNewInfo(int index)
{
    switch(currentGame->getCurrentPlayer())
    {
    case 0:
        buttons[index]->setText("0");
        break;
    case 1:
        buttons[index]->setText("X");
        break;
    }
    setEnabled(true);
    setWindowTitle("Ваш ход");
    currentGame->changeSells(index);
    int curState = currentGame->checkSituation(index);
    getWinner(curState, 3 - curState);
}

void MainWindow::newConfig(int first, int second)
{
    ui->numberToWin->setValue(first);
    ui->sizeOfField->setValue(second);
}

void MainWindow::throwNewConfig()
{
    server->sendMessage('#' + QString::number(ui->numberToWin->value())
                        + '#' + QString::number(ui->sizeOfField->value()));
}

void MainWindow::crashed()
{
    setWindowTitle("Игра оффлайн");
    setVisible(true);
    setEnabled(true);
    gameStates = offline;
    currentGame->setGameStates(offline);
    newGame();
}

void MainWindow::deleteNetworkStaff()
{
    if (server != nullptr)
        delete server;

    if (client != nullptr)
        delete client;

    if (dialog != nullptr)
        delete dialog;
}

void MainWindow::getWinner(int curState, int winner)
{
    switch(curState)
    {
    case 0:
        enterWinner("Ничья");
        enable((int) gameStates);
        break;
    case 1: case 2:
        enterWinner("Победитель: игрок " + QString::number(winner));
        enable((int) gameStates);
        break;
    }
}

void MainWindow::enterWinner(QString msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

void MainWindow::sendMessage(int index)
{
    switch(gameStates)
    {
    case serverGame:
        server->sendMessage(QString::number(index));
        break;
    case clientGame:
        client->sendMessage(QString::number(index));
        break;
    case offline:
        break;
    }
}

/// start game with new config
void MainWindow::enable(int index)
{
    switch(index)
    {
    case 1:
        gameStates = serverGame;
        setWindowTitle("Ваш ход");
        setEnabled(true);
        break;
    case 2:
        gameStates = clientGame;
        setWindowTitle("Ожидание хода соперника");
        setEnabled(false);
        break;
    }
    setVisible(true);
    currentGame->setGameStates(gameStates);
    newGame();
}

void MainWindow::choiceMenu()
{
    gameOffline();
    setEnabled(true);
    deleteNetworkStaff();
    server = new Server();
    client = new Client();
    dialog = new Dialog(server, client);
    connect(dialog, SIGNAL(rejected()), this, SLOT(gameOffline()));
    connect(server, SIGNAL(rejected()), this, SLOT(gameOffline()));
    connect(server, SIGNAL(startPlay(int)), this, SLOT(enable(int)));
    connect(client, SIGNAL(rejected()), this, SLOT(gameOffline()));
    connect(client, SIGNAL(startPlay(int)), this, SLOT(enable(int)));
    connect(client, SIGNAL(throwNewInfo(int)), this, SLOT(catchNewInfo(int)));
    connect(server, SIGNAL(throwNewInfo(int)), this, SLOT(catchNewInfo(int)));
    connect(server, SIGNAL(newOfflineGame()), this, SLOT(crashed()));
    connect(client, SIGNAL(newOfflineGame()), this, SLOT(crashed()));
    connect(client, SIGNAL(newConfig(int,int)), this, SLOT(newConfig(int,int)));
    connect(server, SIGNAL(throwNewConfig()), this, SLOT(throwNewConfig()));
    setVisible(false);
    dialog->show();
}


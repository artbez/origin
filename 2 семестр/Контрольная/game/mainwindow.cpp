#include "mainwindow.h"
#include "findpair.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FindPair *ttt = new FindPair(4, this);
    setCentralWidget(ttt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

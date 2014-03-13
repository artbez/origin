#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedstack.h"
#include "toOpz.h"
#include "calculateByOpz.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signalMapper = new QSignalMapper(this);
    connect(ui->button0, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button0, "0");
    connect(ui->button1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button1, "1");
    connect(ui->button2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button2, "2");
    connect(ui->button3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button3, "3");
    connect(ui->button4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button4, "4");
    connect(ui->button5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button5, "5");
    connect(ui->button6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button6, "6");
    connect(ui->button7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button7, "7");
    connect(ui->button8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button8, "8");
    connect(ui->button9, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->button9, "9");
    connect(ui->buttonAdd, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonAdd, "+");
    connect(ui->buttonNeg, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonNeg, "-");
    connect(ui->buttonMove, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonMove, "*");
    connect(ui->buttonDev, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->buttonDev, "/");

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(addToCalc(QString)));
    connect(ui->buttonEqual, SIGNAL(clicked()), this, SLOT(getResult()));
    connect(ui->buttonClear, SIGNAL(clicked()), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToCalc(QString qStr)
{
    ui->lineEdit->setText(ui->lineEdit->text() + qStr);
}

void MainWindow::getResult()
{
    const int size = 100;
    const char * str = new char[size];
    str = ui->lineEdit->text().toStdString().c_str();
    int answer = calculateByOpz(toOpz(str));
    emit ui->lineEdit->setText(QString::number(answer));
    delete[] str;
}

void MainWindow::clear()
{
    emit ui->lineEdit->setText("");
}

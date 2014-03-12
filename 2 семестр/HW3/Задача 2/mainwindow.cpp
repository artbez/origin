#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->firstNumber, SIGNAL(valueChanged(int)), this, SLOT(sthWasChanged()));
    connect(ui->secondNumber, SIGNAL(valueChanged(int)), this, SLOT(sthWasChanged()));
    connect(ui->sign, SIGNAL(currentIndexChanged(int)), this, SLOT(sthWasChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sthWasChanged()
{
    int first = 0;
    first = ui->firstNumber->value();
    int second = 0;
    second = ui->secondNumber->value();
    QString curr = ui->sign->currentText();
    QString newText = Calculator::calculate(first, second, curr.at(0).toLatin1());
    emit ui->result->setText(newText);
}

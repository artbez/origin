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
    int curr = ui->sign->currentIndex();
    Calculator calc;
    QString newText = calc.calculate(first, second, curr);
    emit ui->result->setText(newText);
}

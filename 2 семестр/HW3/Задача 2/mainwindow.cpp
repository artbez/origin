#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(sthWasChanged()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(sthWasChanged()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(sthWasChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sthWasChanged()
{
    int first = 0;
    first = ui->spinBox->value();
    int second = 0;
    second = ui->spinBox_2->value();
    int result = 0;
    int curr = ui->comboBox->currentIndex();
    bool isOk = true;
    switch (curr)
    {
    case 0:
        result = first + second;
        break;
    case 1:
        result = first - second;
        break;
    case 2:
        result = first * second;
        break;
    case 3:
        if (second != 0)
            result = first / second;
        else
        {
            emit ui->lineEdit->setText("Error");
            isOk = false;
        }
        break;
    }

    if (isOk)
        emit ui->lineEdit->setText(QString::number(result));
}

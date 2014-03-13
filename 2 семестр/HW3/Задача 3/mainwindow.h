#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addToCalc(QString qStr);
    void getResult();
    void clear();

private:
    QSignalMapper * signalMapper;
    Ui::MainWindow *ui;
};

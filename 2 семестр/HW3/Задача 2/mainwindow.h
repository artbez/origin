#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /// slot which get a signal that sth was changed and set new value to lineEdit
    void sthWasChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

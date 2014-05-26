#pragma once

#include "server.h"
#include "client.h"
#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(Server * newServer, Client * newClient, QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    Server * server;
    Client * client;
    QDialogButtonBox * qBox;
};


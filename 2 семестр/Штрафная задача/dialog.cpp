#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(Server *newServer, Client *newClient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    server(newServer),
    client(newClient)
{
    ui->setupUi(this);
    qBox = ui->buttonBox;
    setWindowTitle("Выберете режим");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    if (ui->radioButton->isChecked())
        server->show();
    else
        client->show();
}

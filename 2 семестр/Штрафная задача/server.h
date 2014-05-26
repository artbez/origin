#pragma once

#include <QDialog>
#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QPushButton>
#include <QLayout>
#include <QMessageBox>


namespace Ui {
class Server;
}

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();
    void sendMessage(QString index);

signals:
    void startPlay(int index);
    /// for saving changes of other player
    void throwNewInfo(int index);
    /// start new offline game
    void newOfflineGame();
    void throwNewConfig();

private slots:
    void sessionOpened();
    /// if a client connected the server
    void acceptConnection();
    void startRead();
    void clientDisconnected();
    void on_okButton_clicked();

private:
    /// checks string to valuable to send
    Ui::Server *ui;
    QLabel *statusLabel;
    QLabel *connectionLabel;
    QPushButton *okButton;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;
};

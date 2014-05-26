#pragma once

#include <QDialog>
#include <QtNetwork/QtNetwork>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
    void sendMessage(QString index);

signals:
    void startPlay(int index);
    /// for saving changes of other player
    void throwNewInfo(int index);
    /// start new offline game
    void newOfflineGame();
    /// throw new cofigurations
    void newConfig(int first, int second);

private slots:
    void sessionOpened();
    void displayError(QAbstractSocket::SocketError socketError);
    /// write server's message
    void startRead();
    void serverDisconnected();
    void enableAddressChange();
    void disableAddressChange();
    /// try to connect to server
    void tryConnect();

    void on_okButton_clicked();

private:
    Ui::Client *ui;
    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QPushButton *okButton;
    QPushButton *connectButton;
    QTcpSocket *serverSocket;
    QNetworkSession *networkSession;
    quint16 blockSize;
};

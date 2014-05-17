#include <QMainWindow>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>

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
    void sessionOpened();
    void displayError(QAbstractSocket::SocketError socketError);
    /// send message to server
    void sendMessage();
    /// write server's message
    void startRead();
    /// make sendButton enable
    void enableSendButton();
    void serverDisconnected();
    void enableAddressChange();
    void disableAddressChange();
    /// try to connect to server
    void tryConnect();

private:
    /// let user spend a message by press enter
    void keyPressEvent(QKeyEvent* pe);
    /// checks string to valuable to send
    bool isValid(QString qStr);
    Ui::MainWindow *ui;
    QLabel *hostLabel;
    QLabel *portLabel;
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLineEdit *chatLineEdit;
    QLabel *statusLabel;
    QPushButton *quitButton;
    QPushButton *sendButton;
    QPushButton *connectButton;
    QTcpSocket *serverSocket;
    QNetworkSession *networkSession;
    QTextEdit *textEdit;
    quint16 blockSize;
};

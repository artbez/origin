#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QtNetwork>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QKeyEvent>
#include <QLayout>
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
    void sessionOpened();
    /// if a client connected the server
    void acceptConnection();
    void sendMessage();
    /// write clients's message
    void startRead();
    void clientDisconnected();

private:
    /// let user spend a message by press enter
    void keyPressEvent(QKeyEvent* pe);
    /// checks string to valuable to send
    bool isValid(QString qStr);
    Ui::MainWindow *ui;
    QLabel *statusLabel;
    QLabel *connectionLabel;
    QPushButton *quitButton;
    QPushButton *sendButton;
    QLineEdit *chatLineEdit;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QNetworkSession *networkSession;
    QTextEdit *textEdit;
    quint16 blockSize;
};

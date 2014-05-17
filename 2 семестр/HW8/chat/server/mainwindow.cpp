#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tcpServer(0),
    clientSocket(0),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    statusLabel = ui->statusLabel;
    quitButton = ui->quitButton;
    sendButton = ui->sendButton;
    textEdit = ui->textEdit;
    textEdit->setReadOnly(true);
    chatLineEdit = ui->chatLineEdit;
    chatLineEdit->setEnabled(false);
    connectionLabel = ui->connectionLabel;

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        /// Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        /// If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        statusLabel->setText("Opening network session.");
        networkSession->open();
    }
    else
        sessionOpened();

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    setWindowTitle("Server");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sessionOpened()
 {
     /// Save the used configuration
     if (networkSession)
     {
         QNetworkConfiguration config = networkSession->configuration();
         QString id;
         if (config.type() == QNetworkConfiguration::UserChoice)
             id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
         else
             id = config.identifier();
     }

     tcpServer = new QTcpServer(this);
     if (!tcpServer->listen(QHostAddress::LocalHost, tcpServer->serverPort()))
     {
         QMessageBox::critical(this, "Server",
                               "Unable to start the server: " + tcpServer->errorString());
         close();
         return;
     }

     statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n")
                          .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
 }

void MainWindow::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    sendButton->setEnabled(true);
    chatLineEdit->setEnabled(true);
    connectionLabel->setText("You can write");
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void MainWindow::startRead()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (blockSize == 0)
    {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (clientSocket->bytesAvailable() < blockSize)
             return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    textEdit->textCursor().insertText("client: " + newMessage + '\n');
}

void MainWindow::sendMessage()
{
    if(clientSocket)
    {
        QString tmp = chatLineEdit->text();
        if (!isValid(tmp))
            return;

        sendButton->setEnabled(false);
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        chatLineEdit->clear();
        out << (quint16)tmp.length();
        out << tmp;
        clientSocket->write(block);
        textEdit->textCursor().insertText("you: " + tmp + '\n');
        sendButton->setEnabled(true);
    }
}

void MainWindow::clientDisconnected()
{
    sendButton->setEnabled(false);
    chatLineEdit->setEnabled(false);
    connectionLabel->setText("Wainting any conections");
    QMessageBox::warning(this, "Warning!", "Client disconnected");
}

void MainWindow::keyPressEvent(QKeyEvent* pe)
{
    if(pe->key() == Qt::Key_Return) sendMessage();
}

bool MainWindow::isValid(QString qStr)
{
    int length = qStr.length();
    for (int i = 0; i < length; ++i)
        if (qStr.at(i) != ' ')
            return true;

    return false;
}

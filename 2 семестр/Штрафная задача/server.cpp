#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Server),
    tcpServer(0),
    clientSocket(0),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    statusLabel = ui->statusLabel;
    connectionLabel = ui->connectionLabel;
    okButton = ui->okButton;
    okButton->setEnabled(false);
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

        statusLabel->setText("Открытие сессии.");
        networkSession->open();
    }
    else
        sessionOpened();

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

    setWindowTitle("Настройки сервера");
}

Server::~Server()
{
    delete ui;
}

void Server::sessionOpened()
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
        QMessageBox::critical(this, "Сервер",
                             "Не могу зупустить сервер: " + tcpServer->errorString());
        close();
        return;
    }

    statusLabel->setText(tr("Сервер запущен на\n\nIP: %1\nport: %2\n\n")
                        .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
}

void Server::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    emit throwNewConfig();
    connectionLabel->setText("Вы можете играть");
    okButton->setEnabled(true);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void Server::sendMessage(QString index)
{
    if(clientSocket)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out << (quint16)index.length();
        out << index;
        clientSocket->write(block);
    }
}

void Server::startRead()
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
    if (newMessage.toInt() == -1)
    {
        emit newOfflineGame();
        clientSocket->disconnectFromHost();
        return;
    }

    emit throwNewInfo(newMessage.toInt());
}

void Server::clientDisconnected()
{
    okButton->setEnabled(false);
    connectionLabel->setText("Ожидание подключений");
    emit newOfflineGame();
    QMessageBox::warning(this, "Осторожно!", "Клиент отключился");
}

void Server::on_okButton_clicked()
{
    emit startPlay(1);
    setVisible(false);
}

#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    hostLabel = ui->hostLabel;
    portLabel = ui->portLabel;
    hostCombo = ui->hostBox;
    hostCombo->setEditable(true);
    connectButton = ui->connectButton;
    portLineEdit = ui->portLineEdit;
    /// restrict values in portLineEdit
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    statusLabel = ui->statusLabel;
    okButton = ui->okButton;
    okButton->setEnabled(false);
    /// find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != "localhost")
        hostCombo->addItem("localhost");

    /// find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    /// add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());

    /// add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); ++i)
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());

    serverSocket = new QTcpSocket(this);

    connect(connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
        this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    connect(serverSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(enableAddressChange()));

    setWindowTitle("Настройки клиента");

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
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered)
            config = manager.defaultConfiguration();

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();
    }
}

Client::~Client()
{
    delete ui;
}

void Client::startRead()
{
    QDataStream in(serverSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (blockSize == 0)
    {
        if (serverSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (serverSocket->bytesAvailable() < blockSize)
        return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    if (newMessage.toInt() == -1)
    {
        emit newOfflineGame();
        serverSocket->disconnectFromHost();
        return;
    }
    if (newMessage.at(0) == '#')
    {
        QStringList qStr = newMessage.mid(1).split('#');
        int first = qStr.first().toInt();
        qStr.pop_front();
        int second = qStr.first().toInt();
        emit newConfig(first, second);
    }
    emit throwNewInfo(newMessage.toInt());
}

void Client::sendMessage(QString index)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)index.length();
    out << index;
    serverSocket->write(block);
}

void Client::sessionOpened()
{
    /// Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    okButton->setEnabled(false);
    serverSocket->close();
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "Client",
                               "The host was not found. Please check the "
                                  "host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "Client",
                                  "The connection was refused by the peer. "
                                  "Make sure the fortune server is running, "
                                  "and check that the host name and port "
                                  "settings are correct.");
        break;
    default:
        QMessageBox::information(this, "Client",
            "The following error occurred: " + (serverSocket->errorString()));
    }
    enableAddressChange();
}

void Client::serverDisconnected()
{
    enableAddressChange();
    emit newOfflineGame();
    QMessageBox::warning(this, "Осторожно!", "Сервер отключился");
}

void Client::enableAddressChange()
{
    hostCombo->setEnabled(true);
    portLineEdit->setEnabled(true);
}

void Client::disableAddressChange()
{
    hostCombo->setEnabled(false);
    portLineEdit->setEnabled(false);
    okButton->setEnabled(true);
}

void Client::tryConnect()
{
    disableAddressChange();
    serverSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());

    if (serverSocket->waitForConnected(3000))
    {
        statusLabel->setText("Подключено");
        connectButton->setEnabled(false);
    }
    else
    {
        QMessageBox::information(this, "Клиент", "Истекло время подключения");
        enableAddressChange();
        statusLabel->setText("");
    }
}

void Client::on_okButton_clicked()
{
    emit startPlay(2);
    setVisible(false);
}

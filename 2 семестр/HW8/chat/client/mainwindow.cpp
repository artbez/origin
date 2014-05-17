#include <QLayout>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    hostLabel = ui->hostLabel;
    portLabel = ui->portLabel;
    hostCombo = ui->hostBox;
    hostCombo->setEditable(true);
    quitButton = ui->quitButton;
    quitButton->setAutoDefault(false);
    sendButton = ui->sendButton;
    sendButton->setEnabled(false);
    connectButton = ui->connectButton;
    textEdit = ui->textEdit;
    textEdit->setReadOnly(true);
    chatLineEdit = ui->chatLineEdit;
    chatLineEdit->setEnabled(false);
    portLineEdit = ui->portLineEdit;
    /// restrict values in portLineEdit
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    statusLabel = ui->statusLabel;

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

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    connect(serverSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(enableAddressChange()));

    setWindowTitle("Client");

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRead()
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
    textEdit->textCursor().insertText("Server: " + newMessage + '\n');
}

void MainWindow::sendMessage()
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
    serverSocket->write(block);

    textEdit->textCursor().insertText("You: " + tmp + '\n');
    sendButton->setEnabled(true);
}

void MainWindow::sessionOpened()
{
    /// Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    enableSendButton();

}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
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

void MainWindow::enableSendButton()
{
    sendButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                 !hostCombo->currentText().isEmpty() &&
                                 !portLineEdit->text().isEmpty());
}

void MainWindow::serverDisconnected()
{
    sendButton->setEnabled(false);
    enableAddressChange();
    QMessageBox::warning(this, "Warning!", "Disconnected");
}

void MainWindow::enableAddressChange()
{
    hostCombo->setEnabled(true);
    portLineEdit->setEnabled(true);
}

void MainWindow::disableAddressChange()
{
    hostCombo->setEnabled(false);
    portLineEdit->setEnabled(false);
}

void MainWindow::tryConnect()
{
    if (connectButton->text() == "Disconnect")
    {
        connectButton->setText("Connect");
        serverSocket->close();
        statusLabel->setText("");
        textEdit->setText("");
        chatLineEdit->setEnabled(false);
        return;
    }

    disableAddressChange();
    serverSocket->connectToHost(hostCombo->currentText(), portLineEdit->text().toInt());

    if (serverSocket->waitForConnected(3000))
    {
        enableSendButton();
        chatLineEdit->setEnabled(true);
        statusLabel->setText("Connected");
        connectButton->setText("Disconnect");
    }
    else
    {
        QMessageBox::information(this, "Client", "Connection timed out");
        enableAddressChange();
        statusLabel->setText("");
        chatLineEdit->setEnabled(false);
    }
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

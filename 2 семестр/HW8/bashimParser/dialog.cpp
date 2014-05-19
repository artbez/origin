#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(buttonLoadWasClicked()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(buttonNextWasClicked()));
    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(buttonPlusWasClicked()));
    connect(ui->minusButton, SIGNAL(clicked()), this, SLOT(buttonMinusWasClicked()));
    connect(ui->bayanButton, SIGNAL(clicked()), this, SLOT(buttonBayanWasClicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::buttonLoadWasClicked()
{
    /// loads quotes
    ui->textEdit->setText("Loading...");
    view = new QWebView();
    view->load(QUrl("http://bash.im/"));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(processReply()));
}

void Dialog::buttonNextWasClicked()
{
    /// writes next quote
    if (currentIndexOfElements == lengthOfElements)
        currentIndexOfElements = 0;
    ui->textEdit->setText(elements.at(currentIndexOfElements).toPlainText() + "\n\n");
    ui->ratingEdit->setText(ratings.at(currentIndexOfElements).toPlainText());
    currentIndexOfElements++;
}

void Dialog::buttonPlusWasClicked()
{
    QString qStr = "http://bash.im/quote/" + id.at(currentIndexOfElements).toPlainText().mid(1);
    QUrl url(qStr);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    nam->post(networkRequest, "/rulez");
    changeUrl(1);
}

void Dialog::buttonMinusWasClicked()
{
    QString qStr = "http://bash.im/quote/" + id.at(currentIndexOfElements).toPlainText().mid(1);
    QUrl url(qStr);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    nam->post(networkRequest, "/sux");
    changeUrl(-1);
}

void Dialog::buttonBayanWasClicked()
{
    QString qStr = "http://bash.im/quote/" + id.at(currentIndexOfElements).toPlainText().mid(1);
    QUrl url(qStr);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    nam->post(networkRequest, "/bayan");
}

void Dialog::processReply()
{
    elements = view->page()->mainFrame()->findAllElements("div[class=text]");
    ratings = view->page()->mainFrame()->findAllElements("span[class=rating]");
    id = view->page()->mainFrame()->findAllElements("a[class=id]");
    currentIndexOfElements = 0;
    lengthOfElements = elements.toList().length();
    ui->textEdit->setText("Completed");
}

void Dialog::changeUrl(int k)
{
    int newValue = ui->ratingEdit->text().toInt() + k;
    ui->ratingEdit->setText(QString::number(newValue));
}

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
    ui->textEdit->setText(elements.at(currentIndexOfElements).toPlainText() + "\n\n"
                          + id.at(currentIndexOfElements).toPlainText().mid(1));
    ui->ratingEdit->setText(ratings.at(currentIndexOfElements).toPlainText());
    currentIndexOfElements++;
}

void Dialog::buttonPlusWasClicked()
{
    QString qStr = id.at(currentIndexOfElements).toPlainText().mid(1);
    clickUrl = new QWebView();
   // QUrl url("http://bash.im/quote/" + qStr + "/rulez");
   // QNetworkAccessManager *nam = new QNetworkAccessManager(this);
   // nam->get(QNetworkRequest(url));
    changeUrl(1);
}

void Dialog::buttonMinusWasClicked()
{
    QString qStr = id.at(currentIndexOfElements).toPlainText().mid(1);
   // QUrl("http://bash.im/quote/" + qStr + "/sux").isValid();
    changeUrl(-1);
}

void Dialog::buttonBayanWasClicked()
{
    QString qStr = id.at(currentIndexOfElements).toPlainText().mid(1);
//    QUrl("http://bash.im/quote/" + qStr + "/rulez").isValid();
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

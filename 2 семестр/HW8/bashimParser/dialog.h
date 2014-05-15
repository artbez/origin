#pragma once

#include <QDebug>
#include <QObject>
#include <QLineEdit>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
#include <QDialog>
#include <QDesktopServices>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void buttonLoadWasClicked();
    void buttonNextWasClicked();
    void buttonPlusWasClicked();
    void buttonMinusWasClicked();
    void buttonBayanWasClicked();
    void processReply();

private:
    void changeUrl(int k);
    QWebView *view;
    QWebView *clickUrl;
    QWebElementCollection elements;
    QWebElementCollection ratings;
    QWebElementCollection id;
    int currentIndexOfElements;
    int lengthOfElements;
    Ui::Dialog *ui;
};

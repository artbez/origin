/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *buttonAdd;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *buttonNeg;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonMove;
    QPushButton *button0;
    QPushButton *buttonClear;
    QPushButton *buttonEqual;
    QPushButton *buttonDev;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(370, 261);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font;
        font.setPointSize(14);
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        button1 = new QPushButton(centralWidget);
        button1->setObjectName(QStringLiteral("button1"));

        gridLayout->addWidget(button1, 1, 0, 1, 1);

        button2 = new QPushButton(centralWidget);
        button2->setObjectName(QStringLiteral("button2"));

        gridLayout->addWidget(button2, 1, 1, 1, 1);

        button3 = new QPushButton(centralWidget);
        button3->setObjectName(QStringLiteral("button3"));

        gridLayout->addWidget(button3, 1, 2, 1, 1);

        buttonAdd = new QPushButton(centralWidget);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        gridLayout->addWidget(buttonAdd, 1, 3, 1, 1);

        button4 = new QPushButton(centralWidget);
        button4->setObjectName(QStringLiteral("button4"));

        gridLayout->addWidget(button4, 2, 0, 1, 1);

        button5 = new QPushButton(centralWidget);
        button5->setObjectName(QStringLiteral("button5"));

        gridLayout->addWidget(button5, 2, 1, 1, 1);

        button6 = new QPushButton(centralWidget);
        button6->setObjectName(QStringLiteral("button6"));

        gridLayout->addWidget(button6, 2, 2, 1, 1);

        buttonNeg = new QPushButton(centralWidget);
        buttonNeg->setObjectName(QStringLiteral("buttonNeg"));

        gridLayout->addWidget(buttonNeg, 2, 3, 1, 1);

        button7 = new QPushButton(centralWidget);
        button7->setObjectName(QStringLiteral("button7"));

        gridLayout->addWidget(button7, 3, 0, 1, 1);

        button8 = new QPushButton(centralWidget);
        button8->setObjectName(QStringLiteral("button8"));

        gridLayout->addWidget(button8, 3, 1, 1, 1);

        button9 = new QPushButton(centralWidget);
        button9->setObjectName(QStringLiteral("button9"));

        gridLayout->addWidget(button9, 3, 2, 1, 1);

        buttonMove = new QPushButton(centralWidget);
        buttonMove->setObjectName(QStringLiteral("buttonMove"));

        gridLayout->addWidget(buttonMove, 3, 3, 1, 1);

        button0 = new QPushButton(centralWidget);
        button0->setObjectName(QStringLiteral("button0"));

        gridLayout->addWidget(button0, 4, 0, 1, 1);

        buttonClear = new QPushButton(centralWidget);
        buttonClear->setObjectName(QStringLiteral("buttonClear"));

        gridLayout->addWidget(buttonClear, 4, 1, 1, 1);

        buttonEqual = new QPushButton(centralWidget);
        buttonEqual->setObjectName(QStringLiteral("buttonEqual"));

        gridLayout->addWidget(buttonEqual, 4, 2, 1, 1);

        buttonDev = new QPushButton(centralWidget);
        buttonDev->setObjectName(QStringLiteral("buttonDev"));

        gridLayout->addWidget(buttonDev, 4, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 370, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lineEdit->setText(QString());
        button1->setText(QApplication::translate("MainWindow", "1", 0));
        button2->setText(QApplication::translate("MainWindow", "2", 0));
        button3->setText(QApplication::translate("MainWindow", "3", 0));
        buttonAdd->setText(QApplication::translate("MainWindow", "+", 0));
        button4->setText(QApplication::translate("MainWindow", "4", 0));
        button5->setText(QApplication::translate("MainWindow", "5", 0));
        button6->setText(QApplication::translate("MainWindow", "6", 0));
        buttonNeg->setText(QApplication::translate("MainWindow", "-", 0));
        button7->setText(QApplication::translate("MainWindow", "7", 0));
        button8->setText(QApplication::translate("MainWindow", "8", 0));
        button9->setText(QApplication::translate("MainWindow", "9", 0));
        buttonMove->setText(QApplication::translate("MainWindow", "*", 0));
        button0->setText(QApplication::translate("MainWindow", "0", 0));
        buttonClear->setText(QApplication::translate("MainWindow", "clear", 0));
        buttonEqual->setText(QApplication::translate("MainWindow", "=", 0));
        buttonDev->setText(QApplication::translate("MainWindow", "/", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#include "mainwindow.h"
#include "testLinkedStack.h"
#include "testOpz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    TestingLinkedStack tl;
    QTest::qExec(&tl);
    TestingOpz to;
    QTest::qExec(&to);
    return a.exec();
}

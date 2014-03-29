#include "mainwindow.h"
#include <QApplication>
#include "calculatortest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    TestingCalculator tc;
    QTest::qExec(&tc);
    return a.exec();
}

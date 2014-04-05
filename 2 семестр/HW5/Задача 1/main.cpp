#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <iostream>
#include "testingtree.h"
#include "tree.h"

int main()
{
    TestingTree tt;
    QTest::qExec(&tt);

    QFile file("file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 1;
    }
    QTextStream qts(&file);
    QString example = qts.readAll();

    std::cout << example.toStdString();
    Tree tree(example);
    tree.printTree();
    std::cout << " = " << tree.countTree();
    return 0;
}

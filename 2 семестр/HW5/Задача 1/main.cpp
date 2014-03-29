#include <QCoreApplication>
#include <iostream>
#include "tree.h"
#include <fstream>
#include <string>

int main()
{
    std::ifstream fin("file.txt");
    std::string str;
    std::getline(fin, str);
    fin.close();
    QString qStr = QString::fromStdString(str);
    Tree * tree = new Tree(qStr);
    tree->printTree();
    std::cout << "\n";
    std::cout << tree->countTree();
    delete tree;
    return 0;
}

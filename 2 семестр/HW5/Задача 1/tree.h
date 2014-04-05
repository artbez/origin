#pragma once
#include <QString>
#include "node.h"

class Tree
{
public:
    Tree(const QString& qStr);
    ~Tree();
    /// Method which print a tree
    void printTree();
    /// Method which count a tree
    int countTree();
private:
    /// Method which make a tree from QString
    Node *toTree(const QString& qStr, int &index);
    Node *root;
};

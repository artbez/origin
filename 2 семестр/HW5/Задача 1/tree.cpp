#include "tree.h"
#include "sum.h"
#include "mul.h"
#include "neg.h"
#include "dev.h"
#include "num.h"
#include <iostream>

Tree::Tree(const QString& qStr)
{
    int index = 0;
    root = toTree(qStr, index);
}

Tree::~Tree()
{
    delete root;
}

void Tree::printTree()
{
    root->print();
}

int Tree::countTree()
{
    return root->count();
}

Node *Tree::toTree(const QString& qStr, int& index)
{
    Node *newNode;
    while((qStr.at(index).toLatin1() == ' ') || (qStr.at(index).toLatin1() == ')')) index++;
    if (qStr.at(index).toLatin1() == '(')
    {
        index++;
        switch(qStr.at(index).toLatin1())
        {
        case '+':
            newNode = new Sum();
            break;
        case '-':
            newNode = new Neg();
            break;
        case '*':
            newNode = new Mul();
            break;
        case '/':
            newNode = new Dev();
            break;
        }
        index++;
        newNode->setLeftChild(toTree(qStr, index));
        newNode->setRightChild(toTree(qStr, index));
    }
    else
    {
        int val = 0;
        int powTen = 10;
        if (qStr.at(index).toLatin1() == '-')
        {
            powTen = -10;
            index++;
        }
        while(qStr.at(index).toLatin1() >= '0' && qStr.at(index).toLatin1() <= '9')
        {
            val *= powTen;
            val += (qStr.at(index).toLatin1() - '0');
            index++;
        }
        index++;
        newNode = new Num(val);
    }
    return newNode;
}

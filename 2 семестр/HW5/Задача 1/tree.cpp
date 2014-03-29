#include "tree.h"
#include <iostream>

Tree::Tree(QString qStr)
{
    toTree(qStr);
}

Tree::~Tree()
{
    deleteTree();
}

void Tree::printTree()
{
    root->printTreeNode();
}

int Tree::countTree()
{
    return root->countTreeNode();
}

void Tree::deleteTree()
{
    delete root;
}

void Tree::TreeNode::printTreeNode()
{
    if (sign == nullptr)
        std::cout << value;
    else
    {
        std::cout << "(";
        sign->printSign();
        std::cout << " ";
        leftChild->printTreeNode();
        std::cout << " ";
        rightChild->printTreeNode();
        std::cout << ")";
    }
}

void Tree::toTree(QString qStr)
{
    root = new TreeNode();
    int index = 0;
    root->createL(qStr, index);
}

Tree::TreeNode::~TreeNode()
{
    deleteTreeNode();
}

void Tree::TreeNode::deleteTreeNode()
{
    if (leftChild != nullptr)
        delete leftChild;
    if (rightChild != nullptr)
        delete rightChild;
    if (sign != nullptr)
        delete sign;
}

void Tree::TreeNode::createL(QString qStr, int &index)
{
    while((qStr.at(index).toLatin1() == ' ') || (qStr.at(index).toLatin1() == ')')) index++;
    if (qStr.at(index).toLatin1() == '(')
    {
        index++;
        sign = new Sign(qStr.at(index).toLatin1());
        index++;
        leftChild = new TreeNode();
        rightChild = new TreeNode();
        leftChild->createL(qStr, index);
        rightChild->createL(qStr, index);
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
        value = val;
    }
}

int Tree::TreeNode::countTreeNode()
{
    if (sign == nullptr)
        return value;
    else
    {
        switch (sign->getValue())
        {
        case '+':	return leftChild->countTreeNode() + rightChild->countTreeNode(); break;
        case '*':	return leftChild->countTreeNode() * rightChild->countTreeNode(); break;
        case '-':	return leftChild->countTreeNode() - rightChild->countTreeNode(); break;
        case '/':
        {
            int second = rightChild->countTreeNode();
            if (second != 0)
                return leftChild->countTreeNode() / second;
                else
                {
                    std::cerr << "Division by zero";
                    exit(0);
                }
                break;
            }
         }
         }

    return 0;
}

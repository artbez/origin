#pragma once
#include <QString>
#include "treeinterface.h"
#include "sign.h"

class Tree : public TreeInterface
{
public:
    Tree(QString qStr);
    ~Tree();
    /// Method which print a tree
    void printTree();
    /// Method which count a tree
    int countTree();
    /// Method which delete tree
    void deleteTree();
private:
    /// Method which make a tree from QString
    void toTree(QString qStr);

    /// Helping class which describe a vertex and childrens
    class TreeNode
    {
    public:
        ~TreeNode();
        /// Method which make a treeNode from QString
        void createL(QString qStr, int &index);
        /// Print TreeNode
        void printTreeNode();
        /// Delete TreeNode
        void deleteTreeNode();
        /// Count TreeNode
        int countTreeNode();
    private:
        TreeNode *leftChild = nullptr;
        TreeNode *rightChild = nullptr;
        int value;
        Sign * sign = nullptr;

    };

    TreeNode * root;
};


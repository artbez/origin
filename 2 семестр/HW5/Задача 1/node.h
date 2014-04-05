#pragma once

class Node
{
public:
    virtual ~Node(){}
    virtual int count() = 0;
    virtual void print() = 0;
    void setLeftChild(Node * newLeftChild);
    void setRightChild(Node * newRightChild);
protected:
    Node * leftChild = nullptr;
    Node * rightChild = nullptr;
};

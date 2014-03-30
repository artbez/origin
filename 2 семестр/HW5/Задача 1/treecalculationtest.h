#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "tree.h"

class TestingTree: public QObject
{
    Q_OBJECT

public:
    explicit TestingTree(QObject *parent = 0) : QObject(parent){}

private slots:
    void simpleSumTest()
    {
        Tree * tree = new Tree("(+ 1 2)");
        QVERIFY(tree->countTree() == 3);
        delete tree;
    }

    void simpleMoveTest()
    {
        Tree * tree = new Tree("(* 3 2)");
        QVERIFY(tree->countTree() == 6);
        delete tree;
    }

    void simpleNegTest()
    {
        Tree * tree = new Tree("(- 3 2)");
        QVERIFY(tree->countTree() == 1);
        delete tree;
    }

    void simpleDivTest()
    {
        Tree * tree = new Tree("(/ 4 2)");
        QVERIFY(tree->countTree() == 2);
        delete tree;
    }

    void twoBracketsTest()
    {
        Tree * tree = new Tree("(+ (* 3 2) (/ 4 2))");
        QVERIFY(tree->countTree() == 8);
        delete tree;
    }

    void hardTest()
    {
        Tree * tree = new Tree("(* (+ (* 3 2) (/ 4 2)) (- 7 (/ 4 2)))");
        QVERIFY(tree->countTree() == 40);
        delete tree;
    }
};

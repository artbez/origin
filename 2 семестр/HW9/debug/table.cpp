#include "table.h"
#include <stdio.h>

Table::Table() : size(500), function(new Func1)
{
    matrix = new Node *[size];
    for (int i = 0; i < size; i++)
        matrix[i] = NULL;
}

Table::~Table()
{
    for (int i = 0; i < size; i++)
        while (matrix[i] != NULL)
        {
            Node *tmp = matrix[i];
            matrix[i] = matrix[i]->next;
            delete tmp;
        }

    delete function;
    delete[] matrix;
}

void Table::add(char *s)
{
    if (exist(s))
        return;
    int key = function->hash(s, size);
    Node *tmp = new Node;
    strcpy(tmp->str, s);
    tmp->next = matrix[key];
    matrix[key] = tmp;
}

void Table::del(char *s)
{
    int key = function->hash(s, size);
    if (matrix[key] == NULL)
        return;
    if (strcmp(matrix[key]->str, s) == 0)
    {
        Node *tmp = matrix[key];
        matrix[key] = matrix[key]->next;
        delete tmp;
    }
    else
    {
        Node *tmp = matrix[key];
        while (tmp->next != NULL && strcmp(tmp->next->str, s) != 0)
            tmp = tmp->next;
        if (tmp->next != NULL)
        {
            Node *tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
        }
    }
}

bool Table::exist(char *s)
{
    int key = function->hash(s, size);
    if (matrix[key] == NULL)
        return false;
    else
    {
        Node *tmp = matrix[key];
        while(strcmp(tmp->str, s) != 0 && tmp->next != NULL)
            tmp = tmp->next;
        return (strcmp(tmp->str, s) == 0);
    }
}

int Table::cells()
{
    return size;
}

void Table::stats()
{
    double k = 0;
    lconf = 0;
    conflicts = 0;
    for (int i = 0; i < size; i++)
    {
        int tmp1 = 0;
        if (matrix[i] != NULL)
        {
            Node *tmp = matrix[i];
            k++;
            tmp1++;
            if (tmp->next != NULL)
                conflicts++;
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
                k++;
                tmp1++;
            }
        }
        if (lconf < tmp1)
            lconf = tmp1;
    }
    loadFactor = k / size;
}

void Table::changeFunc(HashFunc *f)
{
    function = f;
    rebuild();
}

void Table::rebuild()
{
    helpMatrix = new Node *[size];
    for (int i = 0; i < size; i++)
        helpMatrix[i] = NULL;

    Node **newMatrix;
    newMatrix = matrix;
    matrix = helpMatrix;
    helpMatrix = newMatrix;

    for (int i = 0; i < size; i++)
        while (helpMatrix[i] != NULL)
        {
            add(helpMatrix[i]->str);
            Node *tmp = helpMatrix[i];
            helpMatrix[i] = helpMatrix[i]->next;
            delete tmp;
        }

    delete[] helpMatrix;
}

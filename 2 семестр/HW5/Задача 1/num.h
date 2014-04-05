#include "node.h"

class Num : public Node
{
public:
    ~Num(){}
    Num(int value);
    void print();
    int count();
private:
    int value;
};

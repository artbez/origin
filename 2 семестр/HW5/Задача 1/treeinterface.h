#include <QString>

class TreeInterface
{
public:
    virtual ~TreeInterface(){}
    /// Method which print a tree
    virtual void printTree() = 0;
    /// Method which count a tree
    virtual int countTree() = 0;
    /// Method which delete tree
    virtual void deleteTree() = 0;
};

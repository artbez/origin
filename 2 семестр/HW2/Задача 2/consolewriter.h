#include "writer.h"

/// Class which can print a matrix as a spiral bypass to file
class ConsoleWriter : public Writer
{
public:
    ~ConsoleWriter(){}
private:
    /// Method which print element of the matrix to console
    void printElement(int el);
};


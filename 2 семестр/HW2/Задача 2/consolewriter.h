#include "writer.h"

/// Class which can print a matrix as a spiral bypass to file
class ConsoleWriter : public Writer
{
public:
    ~ConsoleWriter(){}
    /// Method which can print a matrix as a spiral bypass to file
    void write(int ** arr, int number);
private:
    /// Method which check is it possible or not move to the next cell
    bool step(int ** arr, int &index1, int &index2, int &direct, int sum, int max, int number);
};


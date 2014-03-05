#include "writer.h"
#include <fstream>

/// Class which can print a matrix as a spiral bypass to console
class FileWriter : public Writer
{
public:
    /// Constructor which take a name of file
    FileWriter(const char * newFileName);
    ~FileWriter();
    /// Method which can print a matrix as a spiral bypass to console
    void write(int ** arr, int number);
private:
    /// Method which check is it possible or not move to the next cell
    bool step(int ** arr, int &index1, int &index2, int &direct, int sum, int max, int number);
    std::ofstream fileName;
};

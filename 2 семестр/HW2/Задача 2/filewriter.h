#pragma once

#include "writer.h"
#include <fstream>

/// Class which can print a matrix as a spiral bypass to console
class FileWriter : public Writer
{
public:
    /// Constructor which take a name of file
    FileWriter(const char * newFileName);
    ~FileWriter();
private:
    /// Method which print element of the matrix to file
    void printElement(int el);
    std::ofstream fileName;
};

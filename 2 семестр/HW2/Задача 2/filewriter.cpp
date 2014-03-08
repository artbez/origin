#include "filewriter.h"
#include <iostream>

FileWriter::FileWriter(const char * newFileName)
{
    fileName.open(newFileName);
}

FileWriter::~FileWriter()
{
    fileName.close();
}

void FileWriter::printElement(int el)
{
    fileName << el << " ";
}


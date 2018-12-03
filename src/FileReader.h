#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>
#include <fstream>

class FileReader {
public:
    static std::vector<std::string> readLinesFromFile(std::string);
};

#endif // FILEREADER_H
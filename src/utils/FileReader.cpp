#include "FileReader.h"

using namespace std;

vector<string> FileReader::readLinesFromFile(string filename) {
    ifstream file(filename);

    vector<string> lines;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }

    return lines;
}
#ifndef DAY2_H
#define DAY2_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include "utils/FileReader.h"

class Day2 {
public:
    void solve();

    void scanId(std::string);
    std::string findMatch();
    std::string getMatchingId(std::string, std::string);
    int getDoubleCount();
    int getTripleCount();
    int getChecksum();

    std::vector<std::string> ids;

private:
    int doubles = 0;
    int triples = 0;
};

#endif // DAY2_H
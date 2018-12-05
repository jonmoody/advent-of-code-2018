#ifndef DAY5_H
#define DAY5_H

#include "utils/FileReader.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Day5 {
public:
    void solve();

    std::string parseItem(std::string);
    int findSmallestPolymerLength(std::string);

};

#endif // DAY5_H
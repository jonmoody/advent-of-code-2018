#ifndef DAY4_H
#define DAY4_H

#include "utils/FileReader.h"
#include <string>
#include <vector>
#include <algorithm>

class Day4 {
public:
    void solve();

    void parseItem(std::string);
    void sortItems();

    std::vector<std::string> orderedItems;
};

#endif // DAY4_H
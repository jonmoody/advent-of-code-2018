#ifndef DAY4_H
#define DAY4_H

#include "utils/FileReader.h"
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>
#include <iterator>

class Day4 {
public:
    void solve();

    void parseItem(std::string);
    void sortItems();
    void accumulateGuardSleepTimes();
    std::string getSleepiestGuard();

    std::vector<std::string> orderedItems;
    std::map<std::string, int> guardSleepTimes;
};

#endif // DAY4_H
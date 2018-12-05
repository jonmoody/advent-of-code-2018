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
    std::string getSleepiestMinute(std::string);
    void findMostFrequentlyAsleepMinute();

    std::vector<std::string> orderedItems;
    std::map<std::string, int> guardSleepTimes;
    std::map<std::string, std::map<std::string, int> > sleepyMinutes;

    std::string guardWithMostFrequentlyAsleepMinute;
    std::string mostFrequentlyAsleepMinute;
};

#endif // DAY4_H
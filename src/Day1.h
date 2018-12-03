#ifndef DAY1_H
#define DAY1_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "utils/FileReader.h"

class Day1 {
public:
    void solve();

    void findFrequencyMatch();
    int getSingleFrequency(std::string input);
    int getTotalFrequency();

    std::vector<int> valuesFromFile;

private:
    int frequency = 0;
    std::set<int> frequencyList;
    int numberOfPasses = 1;
};

#endif // DAY1_H
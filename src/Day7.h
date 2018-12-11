#ifndef DAY7_H
#define DAY7_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include "utils/FileReader.h"

class Day7 {
public:
    void solve();

    void parseItem(std::string);
    std::string getOrder();

private:
    std::vector<std::string> dependencies;
};

#endif // DAY7_H
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
#include <deque>
#include "utils/FileReader.h"

class Day7 {
public:
    void solve();

    void parseItem(std::string);
    std::string getOrder();

private:
    std::map<char, std::set<char> > dependencies;
};

#endif // DAY7_H
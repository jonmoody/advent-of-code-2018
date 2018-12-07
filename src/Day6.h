#ifndef DAY6_H
#define DAY6_H

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

struct Point {
    int x = 0;
    int y = 0;
};

class Day6 {
public:
    void solve();

    void parseItem(std::string);
    int getLargestFiniteArea();

private:
    std::vector<Point> points;
    std::vector<std::string> infinite;
    std::map<std::string, int> areaSizes;
};

#endif // DAY6_H
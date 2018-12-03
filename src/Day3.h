#ifndef DAY3_H
#define DAY3_H

#include "utils/FileReader.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>

struct Claim {
    int id = 0;
    int left = 0;
    int top = 0;
    int width = 0;
    int height = 0;
};

struct Point {
    int x = 0;
    int y = 0;
};

class Day3 {
public:
    void solve();

    Claim parseClaim(std::string);

    std::vector<Point> pointsTaken;
};

#endif // DAY3_H
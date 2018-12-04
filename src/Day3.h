#ifndef DAY3_H
#define DAY3_H

#include "utils/FileReader.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>
#include <set>

struct Claim {
    int id = 0;
    int left = 0;
    int top = 0;
    int width = 0;
    int height = 0;
};

class Day3 {
public:
    void solve();

    Claim parseClaim(std::string);
    int getNumberOfOverlappingSquares();
    int getUntouchedClaimId();

    std::set<std::string> pointsTaken;
    std::set<std::string> pointsOverlapping;

private:
    std::vector<Claim> possibleUntouchedClaims;
};

#endif // DAY3_H
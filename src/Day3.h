#ifndef DAY3_H
#define DAY3_H

#include <string>

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
};

#endif // DAY3_H
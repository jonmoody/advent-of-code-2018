#ifndef DAY2_H
#define DAY2_H

#include <string>

class Day2 {
public:
    void solve();

    void scanId(std::string);
    int getDoubleCount();
    int getTripleCount();
    int getChecksum();

private:
    int doubles = 0;
    int triples = 0;
};

#endif // DAY2_H
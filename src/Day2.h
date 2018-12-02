#ifndef DAY2_H
#define DAY2_H

#include <string>

class Day2 {
public:
    void scanId(std::string);
    int getDoubleCount();
    int getTripleCount();

private:
    int doubles = 0;
    int triples = 0;
};

#endif // DAY2_H
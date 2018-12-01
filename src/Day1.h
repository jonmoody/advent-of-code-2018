#ifndef DAY1_H
#define DAY1_H

#include <string>

class Day1 {
public:
    void addFrequency(std::string input);
    int getFrequency();

private:
    int frequency = 0;
};

#endif // DAY1_H
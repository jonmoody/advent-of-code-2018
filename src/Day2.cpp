#include "Day2.h"
#include <map>

using namespace std;

void Day2::scanId(string id) {
    map<char, int> letterCount;
    for (char& letter : id) {
        if (letterCount.find(letter) != letterCount.end()) {
            letterCount.find(letter)->second = letterCount.find(letter)->second + 1;
        } else {
            letterCount[letter] = 1;
        }
    }
    
    for (auto const& x : letterCount) {
        if (x.second == 2) {
            doubles++;
        } else if (x.second == 3) {
            triples++;
        }
    }
}

int Day2::getDoubleCount() {
    return doubles;
}

int Day2::getTripleCount() {
    return triples;
}
#include "Day2.h"

using namespace std;

void Day2::solve() {
    ifstream file("src/input/day2.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            scanId(line);
            ids.push_back(line);
        }
    }



    cout << "Checksum: " << getChecksum() << endl;
}

void Day2::scanId(string id) {
    map<char, int> letterCount;
    for (char& letter : id) {
        if (letterCount.find(letter) != letterCount.end()) {
            letterCount.find(letter)->second = letterCount.find(letter)->second + 1;
        } else {
            letterCount[letter] = 1;
        }
    }

    bool doubleFound = false;
    bool tripleFound = false;
    
    for (auto const& x : letterCount) {
        if (!doubleFound && x.second == 2) {
            doubles++;
            doubleFound = true;
        } else if (!tripleFound && x.second == 3) {
            triples++;
            tripleFound = true;
        }
    }
}

string Day2::getMatchingId(string firstId, string secondId) {
    return "";
}

int Day2::getDoubleCount() {
    return doubles;
}

int Day2::getTripleCount() {
    return triples;
}

int Day2::getChecksum() {
    return getDoubleCount() * getTripleCount();
}
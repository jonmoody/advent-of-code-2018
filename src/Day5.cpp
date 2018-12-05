#include "Day5.h"

using namespace std;

void Day5::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day5.txt");
    for (string line : lines) {
        parseItem(line);
    }
}

void Day5::parseItem(string item) {
    
}
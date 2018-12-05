#include "Day5.h"

using namespace std;

void Day5::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day5.txt");
    string reducedItem = "";
    for (string line : lines) {
        reducedItem = parseItem(line);
    }
    
    cout << "Remaining units: " << reducedItem.length() << endl;
}

string Day5::parseItem(string item) {
    string::iterator previousIt = item.begin();
    string::iterator it = item.begin() + 1;

    while (it != item.end()) {
        if (*previousIt - 32 == *it || *previousIt + 32 == *it) {
            item.erase(previousIt);
            item.erase(previousIt);
            previousIt = item.begin();
            it = item.begin() + 1;
        } else {
            ++previousIt;
            ++it;
        }
    }

    return item;
}
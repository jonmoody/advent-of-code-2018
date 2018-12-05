#include "Day5.h"

using namespace std;

void Day5::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day5.txt");
    string reducedItem = "";
    for (string line : lines) {
        reducedItem = parseItem(line);
    }
    
    cout << "Remaining units: " << reducedItem.length() << endl;
    cout << "Smallest polymer length: " << findSmallestPolymerLength(reducedItem) << endl;
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

int Day5::findSmallestPolymerLength(string item) {
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int smallestCount = item.length();

    for (string::iterator lettersIt = letters.begin(); lettersIt < letters.end(); ++lettersIt) {
        string modifiedItem = item;
        modifiedItem.erase(remove(modifiedItem.begin(), modifiedItem.end(), *lettersIt), modifiedItem.end());
        modifiedItem.erase(remove(modifiedItem.begin(), modifiedItem.end(), *lettersIt + 32), modifiedItem.end());

        string reducedItem = parseItem(modifiedItem);
        int unitCount = reducedItem.length();
        if (unitCount < smallestCount) {
            smallestCount = unitCount;
        }
    }

    return smallestCount;
}
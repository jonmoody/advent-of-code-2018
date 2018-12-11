#include "Day7.h"

using namespace std;

void Day7::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day7.txt");
    for (string line : lines) {
        parseItem(line);
    }

    cout << "Order: " << getOrder() << endl;
}

void Day7::parseItem(string item) {
    dependencies.push_back(item.substr(5, 1) + item.substr(36, 1));
}

string Day7::getOrder() {
    return "";
}
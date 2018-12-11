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
    dependencies[item.at(36)].insert(item.at(5));
    dependencies[item.at(5)];
}

string Day7::getOrder() {
    string answer;
    while (!dependencies.empty()) {
        deque<char> order;

        for (auto& dep : dependencies) {
            if (dep.second.empty()) {
                order.push_back(dep.first);
            }
        }

        char firstLetter = order.front();

        for (auto& dep : dependencies) {
            dep.second.erase(firstLetter);
        }
        answer.push_back(firstLetter);
        dependencies.erase(firstLetter);
    }

    return answer;
}
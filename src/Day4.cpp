#include "Day4.h"

using namespace std;

void Day4::solve() {

}

void Day4::parseItem(string item) {
    orderedItems.push_back(item);
}

void Day4::sortItems() {
    sort(orderedItems.begin(), orderedItems.end());
}
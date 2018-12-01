#include "Day1.h"

using namespace std;

void Day1::addFrequency(string input) {
    if (input.at(0) == '-') {
        frequency -= stoi(input.substr(1));
    }
}

int Day1::getFrequency() {
    return frequency;
}
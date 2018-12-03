#include "Day1.h"

using namespace std;

void Day1::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day1.txt");
    for (string line : lines) {
        valuesFromFile.push_back(getSingleFrequency(line));
    }
    
    findFrequencyMatch();

    cout << "Number of passes: " << numberOfPasses << endl;
    cout << "Matched frequency: " << frequency << endl;
}

void Day1::findFrequencyMatch() {
    auto currentFrequencyChange(valuesFromFile.begin());

    while (frequencyList.find(frequency) == frequencyList.end()) {
        frequencyList.insert(frequency);
        frequency += *currentFrequencyChange;
        ++currentFrequencyChange;

        if (currentFrequencyChange == valuesFromFile.end()) {
            currentFrequencyChange = valuesFromFile.begin();

            if (numberOfPasses == 1) {
                cout << "First pass frequency: " << frequency << endl;
            }
            numberOfPasses++;
        }
    }
}

int Day1::getSingleFrequency(string input) {
    int number = stoi(input.substr(1));

    if (input.at(0) == '-') {
        number *= -1;
    }

    return number;
}

int Day1::getTotalFrequency() {
    return frequency;
}

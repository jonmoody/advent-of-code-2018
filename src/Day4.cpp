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

void Day4::accumulateGuardSleepTimes() {

    string minuteDelim = ":";
    string guardDelim = "#";
    string guard = "";
    string minuteAsleep = "";
    string minuteAwake = "";

    for (string line : orderedItems) {
        istringstream iss(line);
        vector<string> values { istream_iterator<string>{iss}, istream_iterator<string>{}};

        if (line.find("Guard") != string::npos) {
            guard = "#";
            for (string::iterator it = line.begin(); it < line.end(); ++it) {
                if (guardDelim.find(*it) != string::npos) {
                    ++it;
                    guard.push_back(*it);
                    ++it;
                    guard.push_back(*it);
                    cout << "Guard: " << guard << endl;
                }
            }
        }

        if (line.find("asleep") != string::npos) {
            minuteAsleep = "";
            for (string::iterator it = line.begin(); it < line.end(); ++it) {
                if (minuteDelim.find(*it) != string::npos) {
                    ++it;
                    minuteAsleep.push_back(*it);
                    ++it;
                    minuteAsleep.push_back(*it);
                    cout << "Minute asleep: " << minuteAsleep << endl;
                }
            }
        }

        if (line.find("wakes") != string::npos) {
            minuteAwake = "";
            for (string::iterator it = line.begin(); it < line.end(); ++it) {
                if (minuteDelim.find(*it) != string::npos) {
                    ++it;
                    minuteAwake.push_back(*it);
                    ++it;
                    minuteAwake.push_back(*it);
                    cout << "Minute awake: " << minuteAwake << endl;

                    guardSleepTimes[guard] += stoi(minuteAwake) - stoi(minuteAsleep);

                    cout << "Guard " << guard << " sleep time: " << guardSleepTimes[guard] << endl;
                }
            }
        }
    }
}

string Day4::getSleepiestGuard() {
    string guardId = "";
    int sleepTime = 0;

    for (auto const& guard : guardSleepTimes) {
        if (guard.second > sleepTime) {
            guardId = guard.first;
            sleepTime = guard.second;
        }
    }

    return guardId;
}
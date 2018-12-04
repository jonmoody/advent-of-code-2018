#include "Day3.h"

using namespace std;

void Day3::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day3.txt");
    for (string line : lines) {
        parseClaim(line);
    }

    cout << "Number of overlapping squares: " << getNumberOfOverlappingSquares() << endl;
    cout << "Untouched claim id: " << getUntouchedClaimId() << endl;
}

Claim Day3::parseClaim(string claimInput) {
    string removeChars = ",:x#@";
    for (string::iterator it = claimInput.begin(); it < claimInput.end(); ++it) {
        if (removeChars.find(*it) != string::npos) {
            *it = ' ';
        }
    }

    istringstream iss(claimInput);
    vector<string> values { istream_iterator<string>{iss}, istream_iterator<string>{}};

    Claim claim = { stoi(values.at(0)), stoi(values.at(1)), stoi(values.at(2)), stoi(values.at(3)), stoi(values.at(4)) };

    bool claimRemoved = false;
    possibleUntouchedClaims.push_back(claim);

    for (int y = claim.top; y < claim.top + claim.height; y++) {
        for (int x = claim.left; x < claim.left + claim.width; x++) {
            string newPoint = to_string(x) + "," + to_string(y);

            if (!pointsTaken.insert(newPoint).second) {
                pointsOverlapping.insert(newPoint);

                if (!claimRemoved) {
                    possibleUntouchedClaims.pop_back();
                    claimRemoved = true;
                }
            } 
        }
    }

    return claim;
}

int Day3::getNumberOfOverlappingSquares() {
    return pointsOverlapping.size();
}

int Day3::getUntouchedClaimId() {
    for (Claim claim : possibleUntouchedClaims) {
        bool correctId = true;

        for (int y = claim.top; y < claim.top + claim.height; y++) {
            for (int x = claim.left; x < claim.left + claim.width; x++) {
                string point = to_string(x) + "," + to_string(y);

                if (pointsOverlapping.find(point) != pointsOverlapping.end()) {
                    correctId = false;
                }
            }
        }

        if (correctId) {
            return claim.id;
        }
    }
    return 0;
}
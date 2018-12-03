#include "Day3.h"

using namespace std;

void Day3::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day3.txt");
    int x = 0;
    for (string line : lines) {
        cout << "Reading line: " << x << endl;
        x++;
        parseClaim(line);
    }

    cout << "Number of overlapping squares: " << getNumberOfOverlappingSquares() << endl;
}

Claim Day3::parseClaim(string claimInput) {
    replace(claimInput.begin(), claimInput.end(), ',', ' ');
    replace(claimInput.begin(), claimInput.end(), ':', ' ');
    replace(claimInput.begin(), claimInput.end(), 'x', ' ');
    replace(claimInput.begin(), claimInput.end(), '#', ' ');
    replace(claimInput.begin(), claimInput.end(), '@', ' ');

    istringstream iss(claimInput);
    vector<string> values { istream_iterator<string>{iss}, istream_iterator<string>{}};

    Claim claim;
    claim.id = stoi(values.at(0));
    claim.left = stoi(values.at(1));
    claim.top = stoi(values.at(2));
    claim.width = stoi(values.at(3));
    claim.height = stoi(values.at(4));

    for (int y = claim.top; y < claim.top + claim.height; y++) {
        for (int x = claim.left; x < claim.left + claim.width; x++) {
            Point newPoint;
            newPoint.x = x;
            newPoint.y = y;

            for (Point existingPoint : pointsTaken) {
                if (newPoint == existingPoint && find(pointsOverlapping.begin(), pointsOverlapping.end(), newPoint) == pointsOverlapping.end()) {
                    pointsOverlapping.push_back(newPoint);
                }
            }

            if (find(pointsTaken.begin(), pointsTaken.end(), newPoint) == pointsTaken.end()) {
                pointsTaken.push_back(newPoint);
            }
        }
    }

    return claim;
}

int Day3::getNumberOfOverlappingSquares() {
    return pointsOverlapping.size();
}
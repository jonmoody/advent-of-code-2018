#include "Day6.h"

using namespace std;

void Day6::solve() {
    vector<string> lines = FileReader::readLinesFromFile("src/input/day6.txt");
    for (string line : lines) {
        parseItem(line);
    }

    cout << "Greatest finite area size: " << getLargestFiniteArea() << endl;
}

void Day6::parseItem(string item) {
    item.erase(item.find(' '), 1);

    vector<string> tokens;
    string token;
    istringstream tokenStream(item);

    while (getline(tokenStream, token, ','))
    {
        tokens.push_back(token);
    }

    Point point = { stoi(tokens.at(0)), stoi(tokens.at(1)) };
    points.push_back(point);
    areaSizes[item] = 0;
}

int Day6::getLargestFiniteArea() {
    int size = 500;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int shortestDistance = 1000;
            string closestPoint = "";
            bool equalDistance = false;
            bool infinite = false;

            for (Point point : points) {
                int distance = abs(point.x - x) + abs(point.y - y);
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    closestPoint = to_string(point.x) + "," + to_string(point.y);
                    equalDistance = false;

                    infinite = (x == 0 || y == 0 || x == size - 1 || y == size - 1);
                } else if (distance == shortestDistance) {
                    equalDistance = true;
                }
            }

            if (infinite) {
                areaSizes[closestPoint] = 100000;
            }
            if (!equalDistance && areaSizes[closestPoint] != 100000) {
                areaSizes[closestPoint] += 1;
            }
        }
    }

    int greatestFiniteDistance = 0;
    for (auto const& area : areaSizes) {
        if (area.second != 100000 && area.second > greatestFiniteDistance) {
            greatestFiniteDistance = area.second;
        }
    }

    return greatestFiniteDistance;
}
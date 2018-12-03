#include "Day3.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

void Day3::solve() {

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

    return claim;
}
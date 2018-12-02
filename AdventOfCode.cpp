#include <iostream>
#include "src/Day1.h"
#include "src/Day2.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Advent of Code 2018" << endl;
    cout << "===================" << endl;
    cout << "Day 1" << endl;
    Day1 day1;
    day1.solve();

    cout << "===================" << endl;
    cout << "Day 2" << endl;
    Day2 day2;
    day2.solve();

    return 0;
}

#include <iostream>
#include "src/Day1.h"
#include "src/Day2.h"
#include "src/Day3.h"
#include "src/Day4.h"
#include "src/Day5.h"
#include "src/Day6.h"
#include "src/Day7.h"

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

    cout << "===================" << endl;
    cout << "Day 3" << endl;
    Day3 day3;
    day3.solve();

    cout << "===================" << endl;
    cout << "Day 4" << endl;
    Day4 day4;
    day4.solve();

    cout << "===================" << endl;
    cout << "Day 5" << endl;
    Day5 day5;
    day5.solve();

    cout << "===================" << endl;
    cout << "Day 6" << endl;
    Day6 day6;
    day6.solve();

    cout << "===================" << endl;
    cout << "Day 7" << endl;
    Day7 day7;
    day7.solve();

    return 0;
}

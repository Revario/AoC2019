// AoC2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"


int main()
{
    std::cout << "Day 1 result: Part1:" << Day1::CalcAllFuel(false) << " Part2: " << Day1::CalcAllFuel(true) << endl;

    Day2 d2;
    std::cout << "Day 2 result: Part1:" << d2.RunCalculation() << " Part2: " << d2.FindVerbNoun() << endl;
    

    auto start = std::chrono::high_resolution_clock::now();


    Day3 d3;
    std::cout << "Day 3 result: Part1:" << d3.CalculateDistanceOfClosest(); //<< " Part2: " << d2.FindVerbNoun() << endl;
    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Time spent: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() ;

    std::cout << "part 2: " << d3.FindClosestByStep() << endl;


    Day4 d4;
    std::cout << "Day 4 result: Part 1:" << d4.PossiblePasswordCount() << " Part 2: " << d4.ProperPasswordCount() << endl; //<< " Part2: " << d2.FindVerbNoun() << endl;


}

    


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

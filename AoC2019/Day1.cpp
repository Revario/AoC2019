#include "Day1.h"

int Day1::CalcFuel(int mass)
{
	return mass / 3 - 2;
}

int Day1::CalcFuelWithFuel(int mass)
{
	int fuel = 0;

	int f = 0;
	while ((f = CalcFuel(mass)) > 0) {
		fuel += f;
		mass = f;
	}

	return fuel;
}

int Day1::CalcAllFuel(bool withFuel)
{
	auto lines = AoC::ReadInputLineByLine("Day1Input.txt");

	int massSum = 0;

	for (vector<string>::const_iterator cit = lines.begin(); cit != lines.end(); ++cit) {
		auto mass = atoi(cit->c_str());


		massSum += withFuel ? CalcFuelWithFuel(mass) : CalcFuel(mass);
		
	}
	
	return massSum;
}

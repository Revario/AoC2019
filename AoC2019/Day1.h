#pragma once
#include "AoC.h"
#include <algorithm>

class Day1 :
	public AoC
{

public:
	static int CalcFuel(int mass);
	static int CalcFuelWithFuel(int mass);

	static int CalcAllFuel(bool withFuel);
};


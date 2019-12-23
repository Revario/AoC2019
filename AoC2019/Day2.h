#pragma once
#include "AoC.h"
class Day2 :
	public AoC
{
public:

	int RunCalculation();
	int FindVerbNoun();

private:
	vector<int> nums_;

	void GetAllNums();

	void CreateProgram();
};


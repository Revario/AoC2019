#pragma once
#include "AoC.h"
class Day4 :
	public AoC
{
public:

	int PossiblePasswordCount();
	int ProperPasswordCount();
private:
	bool CheckIfPossiblePassword(int& current);
	bool CheckIfProperPassword(int& current);
	bool CheckDuplicate(string& s);
	bool CheckProperDuplicate(string& s);
	bool CheckDescending(string& s);
};


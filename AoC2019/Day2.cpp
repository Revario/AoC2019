#include "Day2.h"

void Day2::GetAllNums()
{

	auto numStrings = ReadDelimitedInput("Day2Input.txt", ',');

	for (auto cit = numStrings.begin(); cit != numStrings.end(); ++cit) {
		nums_.emplace_back(atoi(cit->c_str()));
	}
}

void Day2::CreateProgram()
{

	//nums_ = { 1,0,0,0,99 };
	//nums_ = { 2,3,0,3,99 };
	//nums_ = { 2,4,4,5,99,0 };
	//nums_ = { 1,1,1,4,99,5,6,0,99 };*/

	int currPos = 0;
	while (true) {
		if (nums_.at(currPos) == 1) {
			nums_[nums_[currPos + 3]] = nums_[nums_[currPos + 1]] + nums_[nums_[currPos + 2]];
		}
		else if (nums_.at(currPos) == 2) {
			nums_[nums_[currPos + 3]] = nums_[nums_[currPos + 1]] * nums_[nums_[currPos + 2]];
		}
		else if (nums_.at(currPos) == 99) {
			break;
		}
		else
		{
			//throw exception("Unknown opcode detected");
			break;
		}

		if (currPos + 4 >= nums_.size()) {
			break;
		}
		currPos += 4;
	}
}

int Day2::RunCalculation()
{
	GetAllNums();
	nums_[1] = 12;
	nums_[2] = 2;
	CreateProgram();

	return nums_[0];
}

int Day2::FindVerbNoun()
{
	GetAllNums();

	vector<int> nums = nums_;

	for (int v = 0; v < 100; ++v) {
		for(int n = 0; n < 100; ++n){
			nums_ = nums;
			nums_[1] = n;
			nums_[2] = v;
			try {
				CreateProgram();
			}
			catch (...) {
				continue;
			}
			if (nums_[0] == 19690720) {
				return 100 * n + v;
			}
		}
	}
	return 0;
}

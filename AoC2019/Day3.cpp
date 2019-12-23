#include "Day3.h"
#include <algorithm>
#include <unordered_map>

int Day3::CalculateDistanceOfClosest()
{
	vector<string> inputLines = AoC::ReadInputLineByLine("Day3Input.txt");

	FillMap(AoC::Split(inputLines[0], ','));

	auto crossings = FindCrossings(AoC::Split(inputLines[1], ','));

	int closest = 0;

	for (auto c : crossings) {

		auto a = abs(c.first) + abs(c.second);

		if (closest == 0 || a < closest) {
			closest = a;
		}
	}

	return closest;
}

int Day3::FindClosestByStep()
{
	vector<string> inputLines = AoC::ReadInputLineByLine("Day3Input.txt");

	auto crossings = FindCrossings(AoC::Split(inputLines[1], ','));


	auto lowestSteps = 0;

	for (auto c : crossings) {
		auto steps = CountSteps(c, inputLines);

		if (lowestSteps == 0 || steps < lowestSteps) {
			lowestSteps = steps;
		}
	}

	return lowestSteps;
}

int Day3::CountSteps(pair<int, int> pos, vector<string> inputLines) {

	int x = 0;
	int y = 0;

	int count1 = CountForLine(pos, AoC::Split(inputLines[0], ','));

	int count2 = CountForLine(pos, AoC::Split(inputLines[1], ','));


	return count1 + count2;

}

int Day3::CountForLine(pair<int, int> needle, vector<string> input) {
	
	int x = 0;
	int y = 0;

	int count = 0;

	
	for (auto cit = input.begin(); cit != input.end(); ++cit) {

		Direction dir;
		ParseDirection(cit->at(0), dir);

		int len = atoi((cit->substr(1)).c_str());
		for (int i = 0; i < len; ++i) {
			Move(dir, x, y);

			count++;

			if (make_pair(x, y) == needle) {
				return count;
			}

		}
	}

	return -1;

}

vector<pair<int, int> > Day3::FindCrossings(vector<string> input) {

	vector<pair<int, int>> crossings;

	int x = 0;
	int y = 0;

	auto a = "X" + to_string(x) + "Y" + to_string(y);

	for (auto cit = input.begin(); cit != input.end(); ++cit) {

		Direction dir;
		ParseDirection(cit->at(0), dir);

		int len = atoi((cit->substr(1)).c_str());
		for (int i = 0; i < len; ++i) {
			Move(dir, x, y);

			a = "X" + to_string(x) + "Y" + to_string(y);

			auto found = posMap.find(a);

			if (found != posMap.end()) {
				crossings.emplace_back(make_pair(x, y));
			}

		}
	}

	return crossings;

}


void Day3::FillMap(vector<string> input) {

	int x = 0;
	int y = 0;

	auto a = "X" + to_string(x) + "Y" + to_string(y);


	posMap.try_emplace(a, make_pair(x, y));


	for (auto cit = input.begin(); cit != input.end(); ++cit) {

		Direction dir;
		ParseDirection(cit->at(0), dir);

		int len = atoi((cit->substr(1)).c_str());
		for (int i = 0; i < len; ++i) {
			Move(dir, x, y);
			
			a = "X" + to_string(x) + "Y" + to_string(y);

			posMap.try_emplace(a, make_pair(x, y));

		}
	}
	return;
}

void Day3::Move(const Direction d, int& x, int& y)
{
	if (d == Direction::Up) { ++y; }
	if (d == Direction::Down) { --y; }
	if (d == Direction::Left) { --x; }
	if (d == Direction::Right) { ++x; }

}

void Day3::ParseDirection(char& dir, Direction& d) {
	if (dir == 'U') { d = Direction::Up; }
	if (dir == 'D') { d = Direction::Down; }
	if (dir == 'L') { d = Direction::Left; }
	if (dir == 'R') { d = Direction::Right; }
}

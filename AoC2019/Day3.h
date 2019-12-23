#pragma once
#include "AoC.h"
#include <unordered_map>
class Day3 :
	public AoC
{

	enum Direction {
		Up,
		Down,
		Left,
		Right
	};

public:
	int CalculateDistanceOfClosest();
	int FindClosestByStep();
	int CountSteps(pair<int, int> pos, vector<string> input);
private:
	int CountForLine(pair<int, int>, vector<string> input);
	vector<pair<int, int> > FindCrossings(vector<string> input);
	unordered_map<string, pair<int, int> > posMap;
	//vector<pair<int, int> > FindCrossings(vector<pair<int, int> >& firstLine, vector<pair<int, int> >& secondLine);

	void FillMap(vector<string> input);


	//vector<pair<int, int> > DrawLine(vector<string> input);
	void Move(const Direction d, int& x, int& y);
	void ParseDirection(char& dir, Direction& d);
};


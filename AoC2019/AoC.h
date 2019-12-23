#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class AoC
{

public:

	static vector<string> ReadInputLineByLine(string path);

	static string ReadAll(string path);

	static vector<string> ReadDelimitedInput(string path, char delimiter);

	static vector<string> Split(string s, char delimiter);

};


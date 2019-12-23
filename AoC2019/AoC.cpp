#include "AoC.h"

vector<string> AoC::ReadInputLineByLine(string path)
{
	ifstream f;

	vector<string> lines;

	f.open(path);

	string line;

	while (getline(f, line)) {
		lines.push_back(line);
	}

	f.close();

	return lines;
}

string AoC::ReadAll(string path)
{
	ifstream f;

	f.open(path);

	string s;
	s.reserve(5000);

	string ts;


	while (getline(f, ts)) {
		s += ts;
	}

	f.close();

	return s;
	
}

vector<string> AoC::ReadDelimitedInput(string path, char delimiter)
{
	ifstream f;

	f.open(path);

	vector<string> s;

	string ts;


	while (getline(f, ts, delimiter)) {
		s.push_back(ts);
	}

	f.close();

	return s;

}

vector<string> AoC::Split(string s, char delimiter)
{
	size_t pos = 0, prevPos = 0;
	vector<string> exploded;
	while ((pos = s.find(delimiter, ++pos)) != string::npos) {
		
		exploded.emplace_back(s.substr(prevPos, pos - prevPos));
		prevPos = pos + 1;
	}
	return exploded;
}

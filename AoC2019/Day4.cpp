#include "Day4.h"



int Day4::PossiblePasswordCount() {
	auto input = make_pair(248345, 746315);
	auto current = input.first;

	auto passCounter = 0;

	while (current <= input.second) {

		if (CheckIfPossiblePassword(current)) {
			if (current <= input.second) {

				++passCounter;
			}
		}


		++current;



	}

	return passCounter;
	
}

int Day4::ProperPasswordCount() {
	auto input = make_pair(248345, 746315);
	auto current = input.first;

	auto passCounter = 0;

	while (current <= input.second) {

		if (CheckIfProperPassword(current)) {
			if (current <= input.second) {

				++passCounter;
			}
		}


		++current;



	}

	return passCounter;

}
bool Day4::CheckIfPossiblePassword(int& current) {
	auto s = to_string(current);
	auto isPassword = false;

	if (CheckDescending(s) && CheckDuplicate(s)) {
		isPassword = true;
	}

	current = stoi(s);


	return isPassword;


}

bool Day4::CheckIfProperPassword(int& current) {
	auto s = to_string(current);
	auto isPassword = false;

	if (CheckDescending(s) && CheckProperDuplicate(s)) {
		isPassword = true;
	}

	current = stoi(s);


	return isPassword;


}

bool Day4::CheckDuplicate(string& s) {
	for (size_t i = 1; i < s.length(); ++i) {
		if (s[i] == s[i - 1]) {
			return true;
		}
	}
	return false;
}


bool Day4::CheckProperDuplicate(string& s) {

	for (size_t i = 1; i < s.length(); ++i) {


		if (i == 1) {
			if (s[i] == s[i - 1] && s[i] != s[i + 1]) {
				return true;
			}
		} else if (i == s.length() - 1) {
			if (s[i] == s[i - 1] && s[i] != s[i - 2]) {
				return true;
			}
		}
		else {
			if (s[i] == s[i - 1] && s[i] != s[i - 2] && s[i] != s[i + 1]) {
				return true;
			}
		}
		
		
		/*if(s[i] == s[i -1] && s[i] != s[i - 2] )


		if (s[i] == s[i - 1]) {
			if (i == 1) {
				continue;
			} 
			if (i != s.length()-1) {

			}

			
		}*/
	}
	return false;
}

bool Day4::CheckDescending(string& s) {
	
	//auto changed = false;


	for (size_t i = 1; i < s.length(); ++i) {
		if (s[i] < s[i - 1]) {
			s[i] = s[i - 1];
			//changed = true;
		}
	}

	return true;
}
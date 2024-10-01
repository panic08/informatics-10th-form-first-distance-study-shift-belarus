#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool is_simple(int number) {
	if (number < 2) {
		return false;
	}

	if (number == 2) {
		return true;
	}

	if (number % 2 == 0) {
		return false;
	}

	for (int i = 3; (i * i) <= number; i += 2) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;

}

int main() {
	string input;
	getline(std::cin, input);

	vector<int> votes;

	for (char c : input) {
		if (isdigit(c)) {
			votes.push_back(int(c) - 48);
		}
	}

	int zeroTeam = 0;
	int oneTeam = 0;

	for (int i = 0; i < votes.size(); i++) {
		if (votes[i] == 0) {
			if (is_simple(i + 1)) {
				zeroTeam += 2;
			}
			else {
				zeroTeam += 1;
			}
		}
		else if (votes[i] == 1) {
			if (is_simple(i + 1)) {
				oneTeam += 2;
			}
			else {
				oneTeam += 1;
			}
		}
	}

	cout << oneTeam - zeroTeam;
	
	return 0;
}
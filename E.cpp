#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

void bypass(vector<bool>& simples) {
	simples[1] = true;

	for (int i = 2; i * i < simples.size(); i++) {
		if (!simples[i]) {
			for (int j = i * i; j < simples.size(); j += i) {
				simples[j] = true;
			}
		}
	}
}

int main() {
	string input;
	getline(std::cin, input);

	vector<int> votes;

	for (char c : input) {
		if (isdigit(c)) {
			votes.push_back(int(c) - '0');
		}
	}

	vector<bool> simples(votes.size() + 1);
	bypass(simples);

	int zeroTeam = 0;
	int oneTeam = 0;

	for (int i = 0; i < votes.size(); i++) {
		if (votes[i] == 0) {
			if (!simples[i + 1]) {
				zeroTeam += 2;
			}
			else {
				zeroTeam += 1;
			}
		}
		else if (votes[i] == 1) {
			if (!simples[i + 1]) {
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
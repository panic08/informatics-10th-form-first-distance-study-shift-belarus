#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> strs(n);

	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}

	unordered_map<char, int> frequency_map;

	for (string& str : strs) {
		for (char c : str) {
			frequency_map[c]++;
		}
	}

	char mostFreqChar;
	int freq = INT_MAX;

	for (auto& pair : frequency_map) {
		freq = min(freq, pair.second);
	}

	bool changed = false;

	for (auto& pair : frequency_map) {
		if (pair.second > freq) {
			freq = pair.second;
			mostFreqChar = pair.first;	
			changed = true;
		}
	}

	if (!changed) {
		cout << 0;
		return 0;
	}
	else {
		int count = 0;

		for (string& str : strs) {
			if (str.find(mostFreqChar) == string::npos) {
				count++;
			}
		}

		cout << count;
		return 0;
	}
}
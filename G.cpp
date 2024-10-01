#include <iostream>
#include <vector>
using namespace std;

bool bypass(int n, int m, int &count, vector<vector<char>> &matrix, vector<vector<bool>> &checked, vector<vector<bool>> &banned) {
	if (n < 0 || m < 0 || n >= matrix.size() || m >= matrix[n].size() || banned[n][m]) return false;
	if (checked[n][m]) return true;

	checked[n][m] = true;

	bool ans = false;

	if (matrix[n][m] == 'U') {
		ans = bypass(n - 1, m, count, matrix, checked, banned);
	}
	else if (matrix[n][m] == 'D') {
		ans = bypass(n + 1, m, count, matrix, checked, banned);
	}
	else if (matrix[n][m] == 'L') {
		ans = bypass(n, m - 1, count, matrix, checked, banned);
	}
	else if (matrix[n][m] == 'R') {
		ans = bypass(n, m + 1, count, matrix, checked, banned);
	}

	if (ans) {
		count++;
		return true;
	}
	else {
		checked[n][m] = false;
		banned[n][m] = true;
		return false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> checked(n, vector<bool>(m));
	vector<vector<bool>> banned(n, vector<bool>(m));
	vector<vector<char>> matrix(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!checked[i][j] && !banned[i][j]) {
				bypass(i, j, count, matrix, checked, banned);
			}
		}
	}

	cout << count;

	return 0;
}
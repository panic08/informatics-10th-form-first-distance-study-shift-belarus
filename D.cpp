#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a;
	cin >> a;

	int mid = a / 2 + 1;

	vector<int> nums;
	nums.push_back(mid);

	int lefter = mid - 1;
	int righter = mid + 1;

	while (lefter != 0 || righter != a + 1) {
		if (lefter != 0) {
			nums.push_back(lefter);
			lefter--;
		}

		if (righter != a + 1) {
			nums.push_back(righter);
			righter++;
		}
	}

	for (int num : nums) {
		cout << num << " ";
	}

	return 0;
}
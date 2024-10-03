#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& nums, int k, int mid) {
	int initK = 1;
	int initKCoords = nums[0];

	for (long num : nums) {
		if (num - initKCoords >= mid) {
			initKCoords = num;
			initK++;

			if (initK >= k) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	sort(nums.begin(), nums.end());

	int l = nums[0];
	int r = nums[nums.size() - 1];

	while (l <= r) {
		int mid = (l + r) / 2;

		if (check(nums, k, mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << r;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<long>& nums, int k, long mid) {
	int initK = 1;
	long initKCoords = nums[0];

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

	vector<long> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	sort(nums.begin(), nums.end());

	long l = nums[0];
	long r = nums[nums.size() - 1];

	while (l <= r) {
		long mid = (l + r) / 2;

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
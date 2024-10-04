// Задача H. Расставить K камер вдоль дороги в подходящих точках так, чтобы минимальное расстояние между камерами
// было как можно больше.
//
// Входные данные:
// В первой строке заданы два числа: N — количество подходящих мест (3 ≤ N ≤ 20 000) и K — количество камер (1 < K < N).
// Во второй строке даны N попарно различных натуральных чисел — координаты мест, не превосходящие 10^9.
//
// Выходные данные:
// Наибольшее возможное допустимое расстояние между камерами.
//
// Ограничения:
// Время: 1 секунда, Память: 64 мегабайта
//
// Сложность: O(N log(max_distance)) по времени, O(N) по памяти

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
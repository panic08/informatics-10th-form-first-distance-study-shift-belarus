#include <iostream>
#include <climits>
#include <math.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int max_num = -1;

	int first = ((a * 10 + b) * 10) + c;
	int second = ((a * 10 + c) * 10) + b;
	int third = ((b * 10 + a) * 10) + c;
	int fourth = ((b * 10 + c) * 10) + a;
	int fifth = ((c * 10 + a) * 10) + b;
	int sixth = ((c * 10 + b) * 10) + a;


	if (first % 2 == 0) {
		max_num = max(max_num, first);
	}

	if (second % 2 == 0) {
		max_num = max(max_num, second);
	}

	if (third % 2 == 0) {
		max_num = max(max_num, third);
	}

	if (fourth % 2 == 0) {
		max_num = max(max_num, fourth);
	}

	if (fifth % 2 == 0) {
		max_num = max(max_num, fifth);
	}

	if (sixth % 2 == 0) {
		max_num = max(max_num, sixth);
	}

	if (max_num == 0) {
		cout << -1;
		return 0;
	}

	cout << max_num;

	return 0;
}
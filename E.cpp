// Задача E. Подсчитать результаты голосования, где участники с простыми номерами имеют два голоса,
// а участники с составными номерами — один голос.
//
// Входные данные:
// Строка, содержащая 0 (ПРОТИВ) и 1 (ЗА), номера начинаются с 1. Количество чисел не более 10^6.
//
// Выходные данные:
// Разница между количеством голосов ЗА и ПРОТИВ.
//
// Ограничения:
// Время: 1 секунда, Память: 64 мегабайта
//
// Сложность: O(N log log N) по времени, O(N) по памяти

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
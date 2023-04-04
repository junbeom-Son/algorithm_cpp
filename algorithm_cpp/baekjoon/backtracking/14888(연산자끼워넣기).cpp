#include <iostream>

using namespace std;

int minResult = 2000000000;
int maxResult = -2000000000;
int n;
int nums[11];
char ops[11];
bool visited[11];

void initializeOps(int index, int num, char op) {
	for (int i = index; i < index + num; ++i) {
		ops[i] = op;
	}
}

int calculate(int n1, int n2, char op) {
	if (op == '+') {
		return n1 + n2;
	}
	if (op == '-') {
		return n1 - n2;
	}
	if (op == '*') {
		return n1 * n2;
	}
	return n1 / n2;
}

void getResult(int num, int prefixResult) {
	if (num == n) {
		if (prefixResult < minResult) {
			minResult = prefixResult;
		}
		if (prefixResult > maxResult) {
			maxResult = prefixResult;
		}
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		getResult(num + 1, calculate(prefixResult, nums[num], ops[i]));
		visited[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	int opNum;
	cin >> opNum;
	int opIndex = 1;
	initializeOps(opIndex, opNum, '+');
	opIndex += opNum;
	cin >> opNum;
	initializeOps(opIndex, opNum, '-');
	opIndex += opNum;
	cin >> opNum;
	initializeOps(opIndex, opNum, '*');
	opIndex += opNum;
	cin >> opNum;
	initializeOps(opIndex, opNum, '/');
	for (int i = 1; i < n; ++i) {
		visited[i] = false;
	}
	getResult(1, nums[0]);
	cout << maxResult << "\n";
	cout << minResult << "\n";
	return 0;
}
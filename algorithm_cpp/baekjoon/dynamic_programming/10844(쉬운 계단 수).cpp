#include <iostream>
#define DIVISOR 1000000000

using namespace std;

long long counts[10];

void countNums() {
	long long tmp[10] = {};
	tmp[1] += counts[0];
	for (int i = 1; i < 9; ++i) {
		tmp[i - 1] += counts[i];
		tmp[i + 1] += counts[i];
	}
	tmp[8] += counts[9];
	for (int i = 0; i < 10; ++i) {
		counts[i] = tmp[i] % DIVISOR;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; ++i) {
		counts[i] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		countNums();
	}
	long long result = 0;
	for (int i = 0; i < 10; ++i) {
		result += counts[i];
		result %= DIVISOR;
	}
	cout << result << "\n";
	return 0;
}
#include <iostream>

using namespace std;

string str;
bool zoac[100];

void printZoacOrder(int left, int right) {
	char minChar = str.at(left);
	int minIdx = left;
	for (int i = left + 1; i <= right; ++i) {
		char c = str.at(i);
		if (minChar > c) {
			minChar = c;
			minIdx = i;
		}
	}
	zoac[minIdx] = true;
	for (int i = 0; i < (int)str.length(); ++i) {
		if (zoac[i]) {
			cout << str.at(i);
		}
	}
	cout << "\n";
	if (minIdx < right) {
		printZoacOrder(minIdx + 1, right);
	}
	if (minIdx > left) {
		printZoacOrder(left, minIdx - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> str;
	printZoacOrder(0, (int)str.length() - 1);
	return 0;
}
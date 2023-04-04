#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int num[8];
int counts[10001];
bool inUse[8];

void printResult(string result, int depth) {
	int lastNum = 0;
	for (int i = 0; i < n; ++i) {
		if (inUse[i]) {
			continue;
		}
		if (num[i] == lastNum) {
			continue;
		}
		if (depth > 1) {
			inUse[i] = true;
			printResult(result + to_string(num[i]) + " ", depth - 1);
			inUse[i] = false;
		}
		else {
			cout << result << num[i] << "\n";
		}
		lastNum = num[i];

	}
}

int main() {
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	sort(num, num + n);


	printResult("", m);
	return 0;
}
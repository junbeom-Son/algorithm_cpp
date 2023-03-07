#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int nums[8];
bool used[8];

void printResult(string result, int depth) {
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (depth > 1) {
			used[i] = true;
			printResult(result + to_string(nums[i]) + " ", depth - 1);
			used[i] = false;
		}
		else {
			cout << result << nums[i] << "\n";
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		used[i] = false;
	}
	sort(nums, nums + n);
	printResult("", m);
	return 0;
}
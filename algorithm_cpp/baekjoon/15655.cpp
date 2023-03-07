#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int nums[8];

void printResult(string result, int depth, int index) {
	if (n - index < depth) {
		return;
	}
	for (int i = index; i < n; ++i) {
		if (depth > 1) {
			printResult(result + to_string(nums[i]) + " ", depth - 1, i + 1);
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
	}
	sort(nums, nums + n);
	printResult("", m, 0);
	return 0;
}
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int nums[8];

void printResult(string result, int depth) {
	int lastNum = 0;
	for (int i = 0; i < n; ++i) {
		if (nums[i] == lastNum) {
			continue;
		}
		if (depth > 1) {
			printResult(result + to_string(nums[i]) + " ", depth - 1);
		}
		else {
			cout << result << nums[i] << "\n";
		}
		lastNum = nums[i];
	}
}

int main() {
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	printResult("", m);
	return 0;
}
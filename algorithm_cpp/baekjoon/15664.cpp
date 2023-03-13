#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int nums[8];
int n, m;

void printResult(string result, int index, int depth) {
	int lastNum = 0;
	for (int i = index; i < n; ++i) {
		if (n - index + 1 <= depth) {
			return;
		}
		if (nums[i] == lastNum) {
			continue;
		}
		if (depth > 1) {
			printResult(result + to_string(nums[i]) + " ", i + 1, depth - 1);
		}
		else {
			cout << result << nums[i] << "\n";
		}
		lastNum = nums[i];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	printResult("", 0, m);
	return 0;
}
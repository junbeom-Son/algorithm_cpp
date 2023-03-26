#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int nums[8];

void printResult(string result, int depth, int index) {
	int lastNum = 0;
	for (int i = index; i < n; ++i) {
		int curNum = nums[i];
		if (curNum == lastNum) {
			continue;
		}
		if (depth > 1) {
			printResult(result + to_string(curNum) + " ", depth - 1, i);
		}
		else {
			cout << result << curNum << "\n";
		}
		lastNum = curNum;
	}
}

int main() {
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	printResult("", m, 0);
	return 0;
}
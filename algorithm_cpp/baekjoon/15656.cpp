#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int nums[7];

void printResult(string result, int depth) {
	for (int i = 0; i < n; ++i) {
		if (depth > 1) {
			printResult(result + to_string(nums[i]) + " ", depth - 1);
		}
		else {
			cout << result << nums[i] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	printResult("", m);
}
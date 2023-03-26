#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int nums[8];

void printResult(string result, int index, int depth) {
	for (int i = index; i < n; ++i) {
		string tmp = to_string(nums[i]);
		if (depth == 1) {
			cout << result << tmp << "\n";
		}
		else {
			printResult(result + tmp + " ", i, depth - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	printResult("", 0, m);
	return 0;
}
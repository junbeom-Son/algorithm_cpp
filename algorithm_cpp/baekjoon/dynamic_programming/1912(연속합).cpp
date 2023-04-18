#include <iostream>

using namespace std;

int nums[100000][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i][0];
	}
	nums[0][1] = nums[0][0];
	for (int i = 1; i < n; ++i) {
		if (nums[i - 1][1] <= 0) {
			nums[i][1] = nums[i][0];
		}
		else {
			nums[i][1] = nums[i - 1][1] + nums[i][0];
		}
	}
	int maxSum = nums[0][1];
	for (int i = 1; i < n; ++i) {
		if (nums[i][1] > maxSum) {
			maxSum = nums[i][1];
		}
	}
	cout << maxSum << "\n";
}
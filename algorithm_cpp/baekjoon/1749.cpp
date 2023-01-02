#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int** nums = new int* [n + 1];
	for (int i = 0; i <= n; ++i) {
		nums[i] = new int[m + 1]();
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> nums[i][j];
			nums[i][j] = nums[i][j] + nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];
		}
	}
	int maxPart = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = i; k <= n; ++k) {
				for (int l = j; l <= m; ++l) {
					int num = nums[k][l] - nums[i - 1][l] - nums[k][j - 1] + nums[i - 1][j - 1];
					maxPart = max(num, maxPart);
				}
			}
		}
	}
	cout << maxPart << "\n";
	return 0;
}
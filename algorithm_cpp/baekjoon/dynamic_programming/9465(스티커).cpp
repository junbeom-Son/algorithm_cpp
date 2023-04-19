#include <iostream>

using namespace std;

int stickers[2][100000];
int dp[2][100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> stickers[i][j];
			}
		}
		dp[0][0] = stickers[0][0];
		dp[1][0] = stickers[1][0];
		if (n > 1) {
			dp[0][1] = stickers[0][1] + dp[1][0];
			dp[1][1] = stickers[1][1] + dp[0][0];
		}
		for (int i = 2; i < n; ++i) {
			dp[0][i] = stickers[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = stickers[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
		}
		int maxScore = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dp[i][j] > maxScore) {
					maxScore = dp[i][j];
				}
			}
		}
		cout << maxScore << "\n";
	}
	return 0;
}
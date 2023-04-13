#include <iostream>

using namespace std;

long long bridgeCounts[31][31];

int main() {
	for (int i = 1; i <= 30; ++i) {
		bridgeCounts[i][i] = 1;
		bridgeCounts[1][i] = i;
	}
	for (int i = 2; i <= 30; ++i) {
		for (int j = i + 1; j <= 30; ++j) {
			bridgeCounts[i][j] = bridgeCounts[i][j - 1] + bridgeCounts[i - 1][j - 1];
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		cout << bridgeCounts[n][m] << "\n";
	}
}
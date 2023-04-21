#include <iostream>

using namespace std;

int n;
long long board[100][100];
long long possible[100][100];

void findWay() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == n - 1 && j == n - 1) break;
			if (possible[i][j] > 0) {
				long long num = board[i][j];
				if (j + num < n) {
					possible[i][j + num] += possible[i][j];
				}
				if (i + num < n) {
					possible[i + num][j] += possible[i][j];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	possible[0][0] = 1;
	findWay();

	cout << possible[n - 1][n - 1] << "\n";
}
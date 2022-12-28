#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int** prefixSums = new int* [N + 1];
	for (int i = 0; i <= N; ++i) {
		prefixSums[i] = new int[M + 1];
	}
	for (int i = 0; i <= N; ++i) {
		prefixSums[i][0] = 0;
	}
	for (int i = 0; i <= M; ++i) {
		prefixSums[0][i] = 0;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> prefixSums[i][j];
			prefixSums[i][j] = prefixSums[i][j] + prefixSums[i - 1][j] + prefixSums[i][j - 1] - prefixSums[i - 1][j - 1];
		}
	}
	int K;
	cin >> K;
	while (K > 0) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << prefixSums[x][y] - prefixSums[i - 1][y] - prefixSums[x][j - 1] + prefixSums[i - 1][j - 1] << "\n";
		--K;
	}
}
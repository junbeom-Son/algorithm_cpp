#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int** numbers = new int* [N + 1];
	for (int i = 0; i <= N; ++i) {
		numbers[i] = new int[N + 1];
	}
	for (int i = 0; i <= N; ++i) {
		numbers[0][i] = 0;
		numbers[i][0] = 0;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> numbers[i][j];
			numbers[i][j] = numbers[i][j] + numbers[i - 1][j] + numbers[i][j - 1] - numbers[i - 1][j - 1];
		}
	}
	while (M > 0) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << numbers[x2][y2] - numbers[x2][y1 - 1] - numbers[x1 - 1][y2] + numbers[x1 - 1][y1 - 1] << "\n";
		--M;
	}
	for (int i = 0; i <= N; ++i) {
		delete[] numbers[i];
	}
	delete[] numbers;
}
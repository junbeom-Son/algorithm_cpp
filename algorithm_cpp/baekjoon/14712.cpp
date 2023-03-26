#include <iostream>

using namespace std;

bool squares[25][25];

int n, m;
int totalCount = 1;

bool isSquare(int row, int col) {
	if (row == 0 || col == 0) {
		return false;
	}
	if (squares[row - 1][col] && squares[row - 1][col - 1] && squares[row][col - 1]) {
		return true;
	}
	return false;
}

void getCount(int row, int col) {
	for (int j = col; j < m; ++j) {
		if (isSquare(row, j)) {
			continue;
		}
		squares[row][j] = true;
		++totalCount;
		getCount(row, j + 1);
		squares[row][j] = false;
	}

	for (int i = row + 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (isSquare(i, j)) {
				continue;
			}
			squares[i][j] = true;
			++totalCount;
			getCount(i, j + 1);
			squares[i][j] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			squares[i][j] = false;
		}
	}
	getCount(0, 0);
	cout << totalCount << "\n";
	return 0;
}
#include <iostream>
#define END 19

using namespace std;

int board[END + 1][END + 1];

int dx[4] = { 0, 1, 1, -1 };
int dy[4] = { 1, 1, 0, 1 };

bool isValidRange(int row, int col) {
	if (row < 1 || row > END || col < 1 || col > END) {
		return false;
	}
	return true;
}

bool isFiveInARow(int row, int col, int color, int direction) {
	int previousX = row - dx[direction];
	int previousY = col - dy[direction];
	if (isValidRange(previousX, previousY)) {
		if (board[previousX][previousY] == color) {
			return false;
		}
	}
	int count = 1;
	while (true) {
		row += dx[direction];
		col += dy[direction];
		if (!isValidRange(row, col)) {
			break;
		}
		if (board[row][col] != color) {
			break;
		}
		++count;
	}
	if (count == 5) {
		return true;
	}
	return false;
}

bool isWon(int row, int col, int color) {
	for (int i = 0; i < 4; ++i) {
		if (isFiveInARow(row, col, color, i)) {
			return true;
		}
	}
	return false;
}

void findWinner() {
	for (int i = 1; i <= END; ++i) {
		for (int j = 1; j <= END; ++j) {
			if (board[i][j] != 0) {
				if (isWon(i, j, board[i][j])) {
					cout << board[i][j] << "\n" << i << " " << j << "\n";
					return;
				}
			}
		}
	}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= END; ++i) {
		for (int j = 1; j <= END; ++j) {
			cin >> board[i][j];
		}
	}
	findWinner();
	return 0;
}
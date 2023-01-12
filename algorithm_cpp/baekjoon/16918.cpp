#include <algorithm>
#include <iostream>

using namespace std;

int r, c, n;
char originalMap[200][200];
char explodedMap[200][200];
char newBombMap[200][200];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void setOriginalMap() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (newBombMap[i][j] == '.') {
				originalMap[i][j] = '.';
			}
			else {
				originalMap[i][j] = explodedMap[i][j];
			}
		}
	}
}

void explodeBomb(int x, int y) {
	explodedMap[x][y] = '.';
	for (int i = 0; i < 4; ++i) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (0 <= nextX && nextX < r && 0 <= nextY && nextY < c) {
			explodedMap[nextX][nextY] = '.';
		}
	}
}

void installBomb() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (originalMap[i][j] == 'O') {
				newBombMap[i][j] = '.';
			}
			else {
				newBombMap[i][j] = 'O';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> n;
	for (int i = 0; i < r; ++i) {
		cin >> originalMap[i];
	}
	if (n == 1) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cout << originalMap[i][j];
			}
			cout << "\n";
		}
	}
	else if (n % 2 == 0) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cout << 'O';
			}
			cout << "\n";
		}
	}
	else {
		for (int time = 2; time <= n; ++time) {
			if (time % 2 == 0) {
				installBomb();
			}
			else {
				for (int i = 0; i < r; ++i) {
					fill(explodedMap[i], explodedMap[i] + c, 'O');
				}
				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < c; ++j) {
						if (originalMap[i][j] == 'O') {
							explodeBomb(i, j);
						}
					}
				}
				setOriginalMap();
			}
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cout << explodedMap[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
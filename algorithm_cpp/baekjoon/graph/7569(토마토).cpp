#include <iostream>
#include <queue>

using namespace std;

class Tomato {
public:
	int row;
	int col;
	int height;
	Tomato(int h, int r, int c) {
		height = h;
		row = r;
		col = c;
	}
};

int n, m, h;
int tomatoes[100][100][100];
int times[100][100][100];
queue<Tomato> q;

void getInput() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> tomatoes[i][j][k];
			}
		}
	}
}

void getInitialRipeTomatoes() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (tomatoes[i][j][k] == 1) {
					Tomato tomato(i, j, k);
					q.push(tomato);
				}
			}
		}
	}
}

void ripenTomato(Tomato tomato, int targetHeight, int targetRow, int targetCol) {
	int height = tomato.height;
	int row = tomato.row;
	int col = tomato.col;
	if (tomatoes[targetHeight][targetRow][targetCol] == 0) { // 아직 익지 않았다면
		tomatoes[targetHeight][targetRow][targetCol] = 1;
		Tomato unRipeTomato(targetHeight, targetRow, targetCol);
		q.push(unRipeTomato);
		times[targetHeight][targetRow][targetCol] = times[height][row][col] + 1;
	}
}

void ripenTomatoes() {
	while (!q.empty()) {
		Tomato tomato = q.front();
		int height = tomato.height;
		int row = tomato.row;
		int col = tomato.col;
		q.pop();
		// 위층, 아래층, 위칸, 아래칸, 왼쪽칸, 오른쪽칸 순
		if (height > 0) { // 맨 위의 층이 아니라면 위 층의 토마토를 익게 만든다.
			ripenTomato(tomato, height - 1, row, col);
		}
		if (height < h - 1) { // 맨 밑 층이 아니라면 아래층의 토마토를 익게 만든다.
			ripenTomato(tomato, height + 1, row, col);
		}
		if (row > 0) { // 맨 위의 칸이 아니라면 위 칸의 토마토를 익게 만든다.
			ripenTomato(tomato, height, row - 1, col);
		}
		if (row < n - 1) { // 맨 아래 칸이 아니라면 아래 칸의 토마토를 익게 만든다.
			ripenTomato(tomato, height, row + 1, col);
		}
		if (col > 0) { // 맨 왼쪽이 아니라면 왼쪽 칸의 토마토를 익게 만든다.
			ripenTomato(tomato, height, row, col - 1);
		}
		if (col < m - 1) { // 맨 오른쪽 칸이 아니라면 오른쪽 칸의 토마토를 익게 만든다.
			ripenTomato(tomato, height, row, col + 1);
		}
	}
}

int getResult() {
	int t = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (tomatoes[i][j][k] == 0) {
					return -1;
				}
				if (times[i][j][k] > t) {
					t = times[i][j][k];
				}
			}
		}
	}
	return t;
}

int main() {
	getInput();
	getInitialRipeTomatoes();
	ripenTomatoes();
	cout << getResult() << "\n";
	return 0;
}
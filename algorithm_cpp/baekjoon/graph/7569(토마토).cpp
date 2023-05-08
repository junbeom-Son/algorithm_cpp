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
	if (tomatoes[targetHeight][targetRow][targetCol] == 0) { // ���� ���� �ʾҴٸ�
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
		// ����, �Ʒ���, ��ĭ, �Ʒ�ĭ, ����ĭ, ������ĭ ��
		if (height > 0) { // �� ���� ���� �ƴ϶�� �� ���� �丶�並 �Ͱ� �����.
			ripenTomato(tomato, height - 1, row, col);
		}
		if (height < h - 1) { // �� �� ���� �ƴ϶�� �Ʒ����� �丶�並 �Ͱ� �����.
			ripenTomato(tomato, height + 1, row, col);
		}
		if (row > 0) { // �� ���� ĭ�� �ƴ϶�� �� ĭ�� �丶�並 �Ͱ� �����.
			ripenTomato(tomato, height, row - 1, col);
		}
		if (row < n - 1) { // �� �Ʒ� ĭ�� �ƴ϶�� �Ʒ� ĭ�� �丶�並 �Ͱ� �����.
			ripenTomato(tomato, height, row + 1, col);
		}
		if (col > 0) { // �� ������ �ƴ϶�� ���� ĭ�� �丶�並 �Ͱ� �����.
			ripenTomato(tomato, height, row, col - 1);
		}
		if (col < m - 1) { // �� ������ ĭ�� �ƴ϶�� ������ ĭ�� �丶�並 �Ͱ� �����.
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
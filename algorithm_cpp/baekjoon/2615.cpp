/*
* 1. �ٵ����� ��ȸ�ϸ� �ٵϵ��� ����ġ�� �װ����� üũ�Ѵ�.(�� �밢��, ���ο�, ���ο�, �� �밢��)
* 2. �� �Ʒ��� ���� �������� �׻� ������ ���� ���� �Ʒ����� üũ�Ѵ�.
* 3. ������ ���� �������� �׻� ������ ���� ���� �������� üũ�Ѵ�.
* 4. üũ ���� �� ���� �����ϸ� ��� �ٷ� ���α׷� ����
*/

#include <iostream>
#define BOARD_LENGTH 19
#define NO_WINNER 0
#define WIN_NUMBER 5

using namespace std;

int goBoard[BOARD_LENGTH + 1][BOARD_LENGTH + 1];
bool checked[BOARD_LENGTH + 1][BOARD_LENGTH + 1][4]; // 0: �� �밢��, 1: ���ο�, 2: �� �밢��, 3: ���ο�

bool wonByHorizontal(int i, int j) {
	int color = goBoard[i][j];
	int count = 0;
	while (j <= BOARD_LENGTH) {
		if (goBoard[i][j] == color) {
			checked[i][j][3] = true;
			++count;
		}
		else {
			break;
		}
		++j;
	}
	if (count == WIN_NUMBER) {
		return true;
	}
	return false;
}

bool wonByAntiPrincipalDiagonal(int i, int j) {
	int color = goBoard[i][j];
	int count = 0;
	if (i < BOARD_LENGTH && j > 1) {
		if (goBoard[i + 1][j - 1] == color) {
			return false;
		}
	}
	while (i > 0 && j <= BOARD_LENGTH) {
		if (goBoard[i][j] == color) {
			checked[i][j][2] = true;
			++count;
		}
		else {
			break;
		}
		--i;
		++j;
	}
	if (count == WIN_NUMBER) {
		return true;
	}
	return false;
}

bool wonByVertical(int i, int j) {
	int color = goBoard[i][j];
	int count = 0;
	while (i <= BOARD_LENGTH) {
		if (goBoard[i][j] == color) {
			checked[i][j][1] = true;
			++count;
		}
		else {
			break;
		}
		++i;
	}
	if (count == WIN_NUMBER) {
		return true;
	}
	return false;
}

bool wonByPrincipalDiagonal(int i, int j) {
	int color = goBoard[i][j];
	int count = 0;
	while (i <= BOARD_LENGTH && j <= BOARD_LENGTH) {
		if (goBoard[i][j] == color) {
			checked[i][j][0] = true;
			++count;
		}
		else {
			break;
		}
		++i;
		++j;
	}
	if (count == WIN_NUMBER) {
		return true;
	}
	return false;
}

bool isWon(int i, int j) {
	if (!checked[i][j][0] && wonByPrincipalDiagonal(i, j)) {
		return true;
	}
	if (!checked[i][j][1] && wonByVertical(i, j)) {
		return true;
	}
	if (!checked[i][j][2] && wonByAntiPrincipalDiagonal(i, j)) {
		return true;
	}
	if (!checked[i][j][3] && wonByHorizontal(i, j)) {
		return true;
	}
	return false;
}

void findWinner() {
	for (int i = 1; i <= BOARD_LENGTH; ++i) {
		for (int j = 1; j <= BOARD_LENGTH; ++j) {
			if (goBoard[i][j] != 0) {
				if (isWon(i, j)) {
					cout << goBoard[i][j] << "\n";
					cout << i << " " << j << "\n";
					return;
				}
			}
		}
	}
	cout << NO_WINNER;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= BOARD_LENGTH; ++i) {
		for (int j = 1; j <= BOARD_LENGTH; ++j) {
			cin >> goBoard[i][j];
		}
	}
	findWinner();
	return 0;
}
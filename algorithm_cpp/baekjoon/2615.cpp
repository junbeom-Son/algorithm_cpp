/*
* 1. 바둑판을 순회하며 바둑돌을 마주치면 네가지를 체크한다.(주 대각선, 세로열, 가로열, 반 대각선)
* 2. 위 아래가 연결 되있으면 항상 위쪽을 먼저 보고 아래쪽을 체크한다.
* 3. 왼쪽이 연결 되있으면 항상 왼쪽을 먼저 보고 오른쪽을 체크한다.
* 4. 체크 했을 때 뭐든 성공하면 즉시 바로 프로그램 종료
*/

#include <iostream>
#define BOARD_LENGTH 19
#define NO_WINNER 0
#define WIN_NUMBER 5

using namespace std;

int goBoard[BOARD_LENGTH + 1][BOARD_LENGTH + 1];
bool checked[BOARD_LENGTH + 1][BOARD_LENGTH + 1][4]; // 0: 주 대각선, 1: 세로열, 2: 반 대각선, 3: 가로열

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
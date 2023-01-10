#include <iostream>
#include <cmath>

using namespace std;

int originalNums[501][501];
int rotatedNums[501][501];

void copyNums(int n) {
	for (int i = 1; i <= n; ++i) {
		originalNums[i][i] = rotatedNums[i][i];
		originalNums[i][(n + 1) / 2] = rotatedNums[i][(n + 1) / 2];
		originalNums[n - i + 1][i] = rotatedNums[n - i + 1][i];
		originalNums[(n + 1) / 2][i] = rotatedNums[(n + 1) / 2][i];
	}
}

void movePrincipalDiagonal(int n, bool clockwise) {
	for (int i = 1; i <= n; ++i) {
		if (clockwise) {
			rotatedNums[i][(n + 1) / 2] = originalNums[i][i];
		}
		else {
			rotatedNums[(n + 1) / 2][i] = originalNums[i][i];
		}
	}
}

void moveMiddleColumn(int n, bool clockwise) {
	for (int i = 1; i <= n; ++i) {
		if (clockwise) {
			rotatedNums[i][n - i + 1] = originalNums[i][(n + 1) / 2];
		}
		else {
			rotatedNums[i][i] = originalNums[i][(n + 1) / 2];
		}
	}
}

void moveAntiPrincipalDiagonal(int n, bool clockwise) {
	for (int i = 1; i <= n; ++i) {
		if (clockwise) {
			rotatedNums[(n + 1) / 2][i] = originalNums[n - i + 1][i];
		}
		else {
			rotatedNums[i][(n + 1) / 2] = originalNums[i][n - i + 1];
		}
	}
}

void moveMiddleRow(int n, bool clockwise) {
	for (int i = 1; i <= n; ++i) {
		if (clockwise) {
			rotatedNums[i][i] = originalNums[(n + 1) / 2][i];
		}
		else {
			rotatedNums[n - i + 1][i] = originalNums[(n + 1) / 2][i];
		}
	}
}

void rotateCounterClockwise(int n) {
	movePrincipalDiagonal(n, false);
	moveMiddleColumn(n, false);
	moveAntiPrincipalDiagonal(n, false);
	moveMiddleRow(n, false);
}

void rotateClockwise(int n) {
	movePrincipalDiagonal(n, true);
	moveMiddleColumn(n, true);
	moveAntiPrincipalDiagonal(n, true);
	moveMiddleRow(n, true);
}

void rotate(int n, int angle) {
	if (angle == 0 || angle == 360) {
		return;
	}
	while (angle != 0) {
		if (angle < 0) {
			rotateCounterClockwise(n);
			angle += 45;
		}
		else {
			rotateClockwise(n);
			angle -= 45;
		}
		copyNums(n);
	}
}

int calculateAngle(int angle) {
	if (abs(angle) <= 180 || angle == 0 || angle == 360) {
		return angle;
	}
	int answer = 360 - abs(angle);
	if (angle > 0) {
		answer = -answer;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		int n, angle;
		cin >> n >> angle;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> originalNums[i][j];
				rotatedNums[i][j] = originalNums[i][j];
			}
		}
		angle = calculateAngle(angle);
		rotate(n, angle);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << originalNums[i][j] << " ";
			}
			cout << "\n";
		}
		--t;
	}
	return 0;
}
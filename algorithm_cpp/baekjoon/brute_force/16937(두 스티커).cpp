#include <cmath>
#include <iostream>

using namespace std;

int h, w, n;
int stickers[100][2];
int maxArea = 0;

bool verticalStick(int h1, int w1, int h2, int w2) { // 세로
	if (max(w1, w2) <= w && h1 + h2 <= h) {
		return true;
	}
	return false;
}

bool horizontalStick(int h1, int w1, int h2, int w2) { // 가로
	if (max(h1, h2) <= h && w1 + w2 <= w) {
		return true;
	}
	return false;
}

bool canStick(int h1, int w1, int h2, int w2) {
	if (horizontalStick(h1, w1, h2, w2) || horizontalStick(h1, w1, w2, h2) || horizontalStick(w1, h1, h2, w2) || horizontalStick(w1, h1, w2, h2)) {
		return true;
	}
	if (verticalStick(h1, w1, h2, w2) || verticalStick(h1, w1, w2, h2) || verticalStick(w1, h1, h2, w2) || verticalStick(w1, h1, w2, h2)) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> h >> w >> n;
	for (int i = 0; i < n; ++i) {
		cin >> stickers[i][0] >> stickers[i][1];
	}

	for (int i = 0; i < n - 1; ++i) {
		int area1 = stickers[i][0] * stickers[i][1];
		for (int j = i + 1; j < n; ++j) {
			int area2 = stickers[j][0] * stickers[j][1];
			if (area1 + area2 > maxArea && canStick(stickers[i][0], stickers[i][1], stickers[j][0], stickers[j][1])) {
				maxArea = area1 + area2;
			}
		}
	}
	cout << maxArea << "\n";
	return 0;
}
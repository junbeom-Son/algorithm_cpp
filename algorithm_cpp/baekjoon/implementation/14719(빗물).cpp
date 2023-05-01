#include <iostream>

using namespace std;

int main() {
	int h, w;
	int blocks[500];
	cin >> h >> w;
	for (int i = 0; i < w; ++i) {
		cin >> blocks[i];
	}
	int total = 0;
	for (int i = 0; i <= h; ++i) {
		int last = -1;
		for (int j = 0; j < w; ++j) {
			if (blocks[j] >= i) { // block이 있는 경우
				if (last > -1) {
					total += j - last - 1;
				}
				last = j;
			}
		}
	}
	cout << total << "\n";
	return 0;
}
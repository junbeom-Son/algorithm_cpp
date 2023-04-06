#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int result = 1;
	while (a < b) {
		if (b % 2 == 1) {
			if (b % 10 == 1) {
				b /= 10;
				++result;
			}
			else {
				b = -1;
			}
		}
		else {
			b /= 2;
			++result;
		}
	}
	if (a > b) {// ½ÇÆÐ
		result = -1;
	}
	cout << result << "\n";
	return 0;
}
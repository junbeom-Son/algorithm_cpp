#include <iostream>

using namespace std;

int smallJump[21];
int bigJump[21];
int withoutVeryBigJump[21];
int result = 2000000000;
int n, k;

void veryBigJump(int start) {
	int tmp[21] = { 0 };
	for (int i = 1; i < start; ++i) {
		tmp[i] = withoutVeryBigJump[i];
	}
	tmp[start] = tmp[start - 3] + k;
	for (int i = start + 1; i <= n; ++i) {
		tmp[i] = min(tmp[i - 1] + smallJump[i - 1], tmp[i - 2] + bigJump[i - 2]);
	}
	result = min(result, tmp[n]);
}

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> smallJump[i] >> bigJump[i];
	}
	cin >> k;
	if (n >= 2) {
		withoutVeryBigJump[2] = smallJump[1];
	}
	for (int i = 3; i <= n; ++i) {
		withoutVeryBigJump[i] = min(withoutVeryBigJump[i - 1] + smallJump[i - 1], withoutVeryBigJump[i - 2] + bigJump[i - 2]);
	}
	result = withoutVeryBigJump[n];
	for (int i = 4; i <= n; ++i) {
		veryBigJump(i);
	}
	cout << result << " ";

	return 0;
}
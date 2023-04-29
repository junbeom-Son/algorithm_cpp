#include <iostream>

using namespace std;

int nums[50000];
bool isEven[50000];
int lastSeqIndex[50000];
int n, k;
int maxLength;

void initialize() {
	for (int i = 0; i < n; ++i) {
		isEven[i] = (nums[i] % 2 == 0);
	}
	lastSeqIndex[n - 1] = n - 1;
	int length = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (isEven[i] == isEven[i + 1]) {
			lastSeqIndex[i] = lastSeqIndex[i + 1];
			++length;
		}
		else {
			lastSeqIndex[i] = i;
			maxLength = max(maxLength, length);
			length = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	initialize();
	for (int i = 0; i < n; ++i) {
		if (!isEven[i]) {
			continue;
		}
		int tmpI = i;
		int tmpK = k;
		int length = 0;
		while (tmpI < n && tmpK >= 0) {
			int count = lastSeqIndex[tmpI] - tmpI + 1;
			if (isEven[tmpI]) {
				length += count;
			}
			else {
				tmpK -= count;
			}
			tmpI = lastSeqIndex[tmpI] + 1;
		}
		maxLength = max(maxLength, length);
	}
	cout << maxLength << "\n";
	return 0;
}
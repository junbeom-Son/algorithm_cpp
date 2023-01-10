#include <iostream>

using namespace std;

int n, k;
int* movedNums;
int* unmovedNums;
int* numsOrder;

void copyNums() {
	for (int i = 1; i <= n; ++i) {
		movedNums[i] = unmovedNums[i];
	}
}

void moveToPreviosOrder() {
	for (int i = 1; i <= n; ++i) {
		unmovedNums[numsOrder[i]] = movedNums[i];
		//cout << unmovedNums[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	movedNums = new int[n + 1];
	unmovedNums = new int[n + 1];
	numsOrder = new int[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> movedNums[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> numsOrder[i];
	}
	while (k > 0) {
		moveToPreviosOrder();
		copyNums();
		--k;
	}
	for (int i = 1; i <= n; ++i) {
		cout << unmovedNums[i] << " ";
	}
	delete[] movedNums;
	delete[] unmovedNums;
	delete[] numsOrder;
	return 0;
}
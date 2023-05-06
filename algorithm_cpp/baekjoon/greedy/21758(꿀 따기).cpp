#include <iostream>

using namespace std;

int honey[100000];
int n;
int total;
int maxHoney;

void calculateEdges(int start, int end, int increment) {
	int sum = (total - honey[start - increment] - honey[start - increment - increment]) * 2;
	if (sum > maxHoney) {
		maxHoney = sum;
	}
	for (int i = start; i > 0 && i < n - 1; i += increment) {
		sum = sum + honey[i - increment] - honey[i] - honey[i];
		if (sum > maxHoney) {
			maxHoney = sum;
		}
	}
}

void calculateMiddle() {
	int sum = total - honey[0] - honey[n - 1] + honey[1];
	if (sum > maxHoney) {
		maxHoney = sum;
	}
	for (int i = 2; i < n - 1; ++i) {
		sum = sum - honey[i - 1] + honey[i];
		if (sum > maxHoney) {
			maxHoney = sum;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> honey[i];
	}
	for (int i : honey) {
		total += i;
	}
	calculateEdges(n - 3, 0, -1);
	calculateEdges(2, n - 1, 1);
	calculateMiddle();

	cout << maxHoney << "\n";
	return 0;
}
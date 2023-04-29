#include <iostream>

using namespace std;

int n, k;
int bridges[5001];
bool possibleToVisit[5001];

void findAccessibleBridges(int from) {
	for (int i = from + 1; i <= n && i - from <= k; ++i) {
		if (possibleToVisit[i]) {
			continue;
		}
		int power = (i - from) * (1 + abs(bridges[from] - bridges[i]));
		if (power <= k) {
			possibleToVisit[i] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> bridges[i];
	}
	possibleToVisit[1] = true;
	for (int i = 1; i < n; ++i) {
		if (!possibleToVisit[i]) {
			continue;
		}
		findAccessibleBridges(i);
		if (possibleToVisit[n]) {
			break;
		}
	}
	cout << (possibleToVisit[n] ? "YES" : "NO") << "\n";
	return 0;
}
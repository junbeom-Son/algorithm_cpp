#include <iostream>

using namespace std;

int visitors[250000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, n, maxVisit = 0, maxCount = 0, curVisitCount = 0;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> visitors[i];
	}
	for (int i = 0; i < n; ++i) {
		curVisitCount += visitors[i];
		if (i - x >= 0) {
			curVisitCount -= visitors[i - x];
		}
		if (curVisitCount == maxVisit) {
			++maxCount;
		}
		if (curVisitCount > maxVisit) {
			maxVisit = curVisitCount;
			maxCount = 1;
		}
	}
	if (maxVisit == 0) {
		cout << "SAD\n";
	}
	else {
		cout << maxVisit << "\n" << maxCount << "\n";
	}
}
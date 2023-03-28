#include <algorithm>
#include <iostream>

using namespace std;

int ropes[100000];

int main() {
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ropes[i];
	}
	int maxWeight = -1;
	sort(ropes, ropes + n);
	for (int i = 0; i < n; ++i) {
		int curWeight = ropes[i] * (n - i);
		if (maxWeight < curWeight) {
			maxWeight = curWeight;
		}
	}
	cout << maxWeight << "\n";
	return 0;
}
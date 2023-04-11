#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int Sanggeun[500000];
int cards[500000];

int hasCard(int num) {
	int start = 0;
	int end = n - 1;
	int lastMid = -1;
	while (true) {
		int mid = (start + end) / 2;
		if (mid == lastMid || start > end) {
			break;
		}
		int current = Sanggeun[mid];
		if (current == num) {
			return 1;
		}
		else if (current > num) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> Sanggeun[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> cards[i];
	}
	sort(Sanggeun, Sanggeun + n);
	for (int i = 0; i < m; ++i) {
		cout << hasCard(cards[i]) << " ";
	}
	return 0;
}
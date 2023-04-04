#include <algorithm>
#include <iostream>

using namespace std;

long long loses[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> loses[i];
	}
	sort(loses, loses + n);
	long long minLose = 0;
	if (n % 2 == 1) {
		--n;
		minLose = loses[n];
	}
	for (int i = 0; i < n / 2; ++i) {
		long long lose = loses[i] + loses[n - 1 - i];
		if (minLose < lose) {
			minLose = lose;
		}
	}
	cout << minLose << "\n";
	return 0;
}
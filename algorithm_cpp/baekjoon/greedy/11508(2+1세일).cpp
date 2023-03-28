#include <algorithm>
#include <iostream>

using namespace std;

int drinks[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> drinks[i];
	}
	sort(drinks, drinks + n, greater<int>());
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 3 == 2) {
			continue;
		}
		sum += drinks[i];
	}
	cout << sum << "\n";
	return 0;
}
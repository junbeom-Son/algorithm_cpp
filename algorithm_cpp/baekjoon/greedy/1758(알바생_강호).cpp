#include <algorithm>
#include <iostream>

using namespace std;

int tips[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tips[i];
	}
	sort(tips, tips + n, greater<int>());
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int tip = tips[i] - i;
		if (tip > 0) {
			sum += tip;
		}

	}
	cout << sum << "\n";
	return 0;
}
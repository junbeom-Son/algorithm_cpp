#include <algorithm>
#include <iostream>

using namespace std;

double drinks[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> drinks[i];
	}
	sort(drinks, drinks + n);
	double sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += drinks[i] / 2;
	}
	sum += drinks[n - 1];
	cout << sum << "\n";
	return 0;
}
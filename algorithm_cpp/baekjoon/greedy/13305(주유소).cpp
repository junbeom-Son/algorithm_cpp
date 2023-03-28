#include <iostream>

using namespace std;

long long distances[100000];
int prices[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> distances[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> prices[i];
	}
	int minPrice = 2000000000;
	long long total = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (minPrice > prices[i]) {
			minPrice = prices[i];
		}
		total += distances[i] * minPrice;
	}
	cout << total << "\n";
	return 0;
}
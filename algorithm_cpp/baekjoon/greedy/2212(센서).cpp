#include <algorithm>
#include <iostream>

using namespace std;

int sensors[10000];
int distances[9999];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> sensors[i];
	}
	sort(sensors, sensors + n);
	for (int i = 1; i < n; ++i) {
		distances[i - 1] = sensors[i] - sensors[i - 1];
	}
	sort(distances, distances + n - 1);
	int result = 0;
	for (int i = 0; i < n - k; ++i) {
		result += distances[i];
	}
	cout << result << "\n";
	return 0;
}
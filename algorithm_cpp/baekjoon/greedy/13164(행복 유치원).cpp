#include <iostream>
#include <queue>

using namespace std;

int heights[300000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> heights[i];
	}
	if (n == k) {
		cout << "0\n";
		return 0;
	}
	priority_queue<int> pq;
	for (int i = 1; i < n; ++i) {
		pq.push(heights[i] - heights[i - 1]);
	}
	int result = heights[n - 1] - heights[0];
	for (int i = 1; i < k; ++i) {
		result -= pq.top();
		pq.pop();
	}
	cout << result << "\n";
	return 0;
}
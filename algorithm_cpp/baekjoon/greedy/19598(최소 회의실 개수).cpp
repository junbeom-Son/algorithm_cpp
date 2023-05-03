#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> times(n);
	for (int i = 0; i < n; ++i) {
		cin >> times[i].first >> times[i].second;
	}
	sort(times.begin(), times.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(times[0].second);
	for (int i = 1; i < n; ++i) {
		if (times[i].first >= pq.top()) {
			pq.pop();
		}
		pq.push(times[i].second);
	}
	cout << pq.size() << "\n";
	return 0;
}
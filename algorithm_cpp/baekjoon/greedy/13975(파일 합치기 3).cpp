#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;
		priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;
		for (int i = 0; i < n; ++i) {
			int num;
			cin >> num;
			pq.push(num);
		}
		unsigned long long cost = 0;
		while (pq.size() > 1) {
			unsigned long long num1 = pq.top();
			pq.pop();
			unsigned long long num2 = pq.top();
			pq.pop();
			cost += num1 + num2;
			pq.push(num1 + num2);
		}
		cout << cost << "\n";
		--t;
	}

}
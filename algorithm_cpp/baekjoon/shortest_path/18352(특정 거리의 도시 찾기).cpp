#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k, x;
int distances[300001];
bool visited[300001];
vector<vector<int>> edges;

void findKDistanceCities() {
	queue<int> cities;
	cities.push(x);
	visited[x] = true;
	while (!cities.empty()) {
		int curCity = cities.front();
		cities.pop();
		for (int nextCity : edges[curCity]) {
			if (!visited[nextCity] && distances[curCity] < k) {
				distances[nextCity] = distances[curCity] + 1;
				cities.push(nextCity);
				visited[nextCity] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k >> x;
	for (int i = 0; i <= n; ++i) {
		edges.push_back(vector<int>());
	}
	for (int i = 0; i < m; ++i) {
		int source, destination;
		cin >> source >> destination;
		edges[source].push_back(destination);
	}
	findKDistanceCities();
	vector<int> result;
	for (int i = 1; i <= n; ++i) {
		if (distances[i] == k && i != x) {
			result.push_back(i);
		}
	}
	if (result.empty()) {
		cout << "-1\n";
		return 0;
	}
	for (int city : result) {
		cout << city << "\n";
	}
	return 0;
}
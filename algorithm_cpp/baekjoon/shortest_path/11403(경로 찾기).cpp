#include <iostream>
#include <queue>

using namespace std;

int graph[100][100];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		queue<int> q;
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] == 1) {
				q.push(j);
			}
		}
		while (!q.empty()) {
			int row = q.front();
			q.pop();
			for (int j = 0; j < n; ++j) {
				if (graph[row][j] == 1 && graph[i][j] == 0) {
					graph[i][j] = 1;
					q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
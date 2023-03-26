#include <iostream>

using namespace std;

int n;
int cities[11][11];
int minDistance = 2000000000;
int start = 0;
bool visited[11];

void findMinDistance(int sequence, int curCity, int distance) {
	if (sequence == 1) {
		start = curCity;
	}
	if (sequence == n) {
		if (cities[curCity][start] == 0) {
			return;
		}
		else {
			if (cities[curCity][start] + distance < minDistance) {
				minDistance = distance + cities[curCity][start];
			}
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i]) {
			continue;
		}
		if (cities[curCity][i] == 0) {
			continue;
		}
		if (cities[curCity][i] + distance >= minDistance) {
			continue;
		}
		visited[i] = true;
		findMinDistance(sequence + 1, i, cities[curCity][i] + distance);
		visited[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> cities[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		visited[i] = false;
	}
	for (int i = 1; i <= n; ++i) {
		visited[i] = true;
		findMinDistance(1, i, 0);
		visited[i] = false;
	}
	cout << minDistance << "\n";
	return 0;
}
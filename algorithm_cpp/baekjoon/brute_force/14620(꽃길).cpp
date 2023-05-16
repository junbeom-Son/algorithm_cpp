#include <iostream>

using namespace std;

int n;
int costs[10][10];
int minCost = 10000;
int curCost;
bool planted[10][10];

bool isPossibleLocation(int row, int col) {
	if (planted[row - 1][col - 1] || planted[row - 1][col] || planted[row - 1][col + 1] || planted[row][col - 1]) {
		return false;
	}
	if (row > 1 && planted[row - 2][col]) {
		return false;
	}
	if (col > 1 && planted[row][col - 2]) {
		return false;
	}
	return true;
}

void calculateCost(int row, int col, int weight) {
	int cost = costs[row - 1][col] + costs[row][col] + costs[row][col - 1] + costs[row][col + 1] + costs[row + 1][col];
	cost *= weight;
	curCost += cost;
}

void findLocations(int row, int col, int depth) {
	if (depth == 3) {
		if (curCost < minCost) {
			minCost = curCost;
		}
		return;
	}
	for (; row < n - 1; ++row) {
		for (; col < n - 1; ++col) {
			if (isPossibleLocation(row, col)) {
				planted[row][col] = true;
				calculateCost(row, col, 1);
				findLocations(row, col + 1, depth + 1);
				calculateCost(row, col, -1);
				planted[row][col] = false;
			}
		}
		col = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> costs[i][j];
		}
	}
	findLocations(1, 1, 0);
	cout << minCost << "\n";
	return 0;
}
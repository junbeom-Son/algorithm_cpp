#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int chickenMap[50][50];
int minDistance = 1000000000;
pair<int, int> chickenHouses[13];
pair<int, int> pickedChickenHouses[13];
int numOfChickenHouses;
int numOfHouses;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int chickenHouseIndex = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> chickenMap[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (chickenMap[i][j] == 1) {
				++numOfHouses;
			}
			else if (chickenMap[i][j] == 2) {
				++numOfChickenHouses;
				chickenHouses[chickenHouseIndex++] = make_pair(i, j);
			}
		}
	}
}

void calculateChickenDistance() {
	queue<pair<int, int>> q;
	bool visited[50][50];
	int distance[50][50];
	int curDistance = 0;
	int visitedHouseCount = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visited[i][j] = false;
			distance[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		q.push(pickedChickenHouses[i]);
		visited[pickedChickenHouses[i].first][pickedChickenHouses[i].second] = true;
	}
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextRow = row + dx[i];
			int nextCol = col + dy[i];
			if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) {
				continue;
			}
			if (visited[nextRow][nextCol]) {
				continue;
			}

			distance[nextRow][nextCol] = distance[row][col] + 1;
			if (chickenMap[nextRow][nextCol] == 1) {
				++visitedHouseCount;
				curDistance += distance[nextRow][nextCol];
			}
			visited[nextRow][nextCol] = true;
			q.push(make_pair(nextRow, nextCol));
		}
		if (visitedHouseCount == numOfHouses) {
			break;
		}
	}
	if (curDistance < minDistance) {
		minDistance = curDistance;
	}
}

void findMinChickenDistance(int index, int chickenHouseCount) {
	if (chickenHouseCount == m) {
		calculateChickenDistance();
	}
	if (index == numOfChickenHouses) {
		return;
	}
	if (numOfChickenHouses - index < m - chickenHouseCount) {
		return;
	}
	for (; index < numOfChickenHouses; ++index) {
		pickedChickenHouses[chickenHouseCount] = chickenHouses[index];
		findMinChickenDistance(index + 1, chickenHouseCount + 1);
	}
}

int main() {
	init();
	findMinChickenDistance(0, 0);
	cout << minDistance << "\n";
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int castle[100][100];
int times[100][100];
int n, m, t;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
pair<int, int> weaponPosition(-1, -1);

queue<pair<int, int>> q;
string fail = "Fail";

void move(pair<int, int> position, pair<int, int> nextPosition) {
	int nextRow = nextPosition.first;
	int nextCol = nextPosition.second;
	if (nextRow == -1 || nextCol == -1) {
		return;
	}
	if (nextRow >= n || nextCol >= m) {
		return;
	}
	int curRow = position.first;
	int curCol = position.second;

	if (times[nextRow][nextCol] == -1) { // 간적 없으면
		if (castle[nextRow][nextCol] != 1) { // 벽이 있으면 전진x
			if (castle[nextRow][nextCol] == 2) {
				weaponPosition.first = nextRow;
				weaponPosition.second = nextCol;
			}
			q.push(make_pair(nextRow, nextCol));
			times[nextRow][nextCol] = times[curRow][curCol] + 1;
		}
	}
}

void savePrincess() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			times[i][j] = -1;
		}
	}
	times[0][0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> position = q.front();
		q.pop();
		int row = position.first;
		int col = position.second;
		for (int i = 0; i < 4; ++i) {
			move(position, make_pair(row + dx[i], col + dy[i]));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> castle[i][j];
		}
	}
	savePrincess();
	int distance = -1;
	if (!(weaponPosition.first == -1 && weaponPosition.second == -1)) {
		distance = times[weaponPosition.first][weaponPosition.second];

		distance += (n - 1 - weaponPosition.first);
		distance += (m - 1 - weaponPosition.second);
	}

	int distanceWithoutWeapon = times[n - 1][m - 1];
	int result = -1;
	if (distanceWithoutWeapon == -1) { // 무기 없이 도달 못하는 경우
		if (distance != -1 && distance <= t) {
			result = distance;
		}
	}
	else { // 무기 없이 도달할 수 있는 경우
		if (distance == -1) {
			if (distanceWithoutWeapon <= t) {
				result = distanceWithoutWeapon;
			}
		}
		else {
			result = distance < distanceWithoutWeapon ? distance : distanceWithoutWeapon;
		}
	}
	if (result > t) {
		result = -1;
	}
	if (result == -1) {
		cout << fail << "\n";
	}
	else {
		cout << result << "\n";
	}
	return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int countries[50][50];
int n, l, r;
bool visited[50][50];
vector<pair<int, int>> shared;
int population;

void getInput() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> countries[i][j];
		}
	}
}

void clearVisited() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visited[i][j] = false;
		}
	}
}

void findSharedCountries(int row, int col) {
	visited[row][col] = true;
	shared.push_back(make_pair(row, col));
	int curPopulation = countries[row][col];
	population += curPopulation;
	if (row > 0) { // 위쪽 확인
		int difference = abs(curPopulation - countries[row - 1][col]);
		if (l <= difference && difference <= r && !visited[row - 1][col]) {
			findSharedCountries(row - 1, col);
		}
	}
	if (row < n - 1) { // 아래쪽 확인
		int difference = abs(curPopulation - countries[row + 1][col]);
		if (l <= difference && difference <= r && !visited[row + 1][col]) {
			findSharedCountries(row + 1, col);
		}
	}
	if (col > 0) { // 왼쪽 확인
		int difference = abs(curPopulation - countries[row][col - 1]);
		if (l <= difference && difference <= r && !visited[row][col - 1]) {
			findSharedCountries(row, col - 1);
		}
	}
	if (col < n - 1) { // 오른쪽 확인
		int difference = abs(curPopulation - countries[row][col + 1]);
		if (l <= difference && difference <= r && !visited[row][col + 1]) {
			findSharedCountries(row, col + 1);
		}
	}
}

void movePopulation() {
	int countryNum = shared.size();
	int populationPerCountry = population / countryNum;
	for (pair<int, int> p : shared) {
		countries[p.first][p.second] = populationPerCountry;
	}
}

int main() {
	getInput();
	int days = 0;
	while (true) {
		clearVisited();
		bool moved = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j]) {
					continue;
				}
				shared.clear();
				shared.reserve(n * n);
				population = 0;
				findSharedCountries(i, j);
				if (shared.size() > 1) {
					moved = true;
					movePopulation();
				}
			}
		}
		if (!moved) {
			break;
		}
		++days;
	}
	cout << days << "\n";
	return 0;
}
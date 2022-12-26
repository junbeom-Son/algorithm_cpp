/*
* ����� �� ������ ã��, ���� �� ���� ���� ������������ ���� �� �� �پ� ���
* 1. N x N ũ���� ������ �ϳ��� ��ȸ�Ѵ�.
* 2. ���� �ִ°��� �߰��ϸ� ����� ���� �ִ��� Ȯ���Ѵ�.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
bool** visited;
vector<string> town;
vector<int> complexes;

int countConnectedHouses(int row, int col, int count) {
	if (town[row].at(col) == '0' || visited[row][col]) {
		return count;
	}
	visited[row][col] = true;
	count++;
	if (row > 0) {
		count = countConnectedHouses(row - 1, col, count);
	}
	if (row < N - 1) {
		count = countConnectedHouses(row + 1, col, count);
	}
	if (col > 0) {
		count = countConnectedHouses(row, col - 1, count);
	}
	if (col < N - 1) {
		count = countConnectedHouses(row, col + 1, count);
	}
	return count;
}

void findComplexes() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (town[i].at(j) == '1' && !visited[i][j]) {
				complexes.push_back(countConnectedHouses(i, j, 0));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	visited = new bool*[N];
	for (int i = 0; i < N; ++i) {
		visited[i] = new bool[N];
		for (int j = 0; j < N; ++j) {
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < N; ++i) {
		string row;
		cin >> row;
		town.push_back(row);
	}
	findComplexes();
	sort(complexes.begin(), complexes.end());
	cout << complexes.size() << "\n";
	for (int i : complexes) {
		cout << i << "\n";
	}
	for (int i = 0; i < N; ++i) {
		delete[] visited[i];
	}
	delete[] visited;
	return 0;
}
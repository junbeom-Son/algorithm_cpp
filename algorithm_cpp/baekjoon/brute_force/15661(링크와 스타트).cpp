#include <cmath>
#include <iostream>

using namespace std;

int powers[20][20];
int n;

int minDiff = 1000000000;
int teamA, teamB;

void initialize() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			teamB += powers[i][j];
		}
	}
}

void addPerson(int num) {
	for (int i = 0; i <= num; ++i) {
		teamA += powers[num][i];
		teamA += powers[i][num];
	}
	for (int i = num + 1; i < n; ++i) {
		teamB -= powers[num][i];
		teamB -= powers[i][num];
	}
}

void minusPerson(int num) {
	for (int i = 0; i <= num; ++i) {
		teamA -= powers[num][i];
		teamA -= powers[i][num];
	}
	for (int i = num + 1; i < n; ++i) {
		teamB += powers[num][i];
		teamB += powers[i][num];
	}
}

void getResult(int person) {
	if (person == n) {
		return;
	}
	int diff = abs(teamA - teamB);
	if (diff < minDiff) {
		minDiff = diff;
	}
	for (int i = person; i < n; ++i) {
		addPerson(i);
		getResult(i + 1);
		minusPerson(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> powers[i][j];
		}
	}
	initialize();
	getResult(0);
	cout << minDiff << endl;
	return 0;
}
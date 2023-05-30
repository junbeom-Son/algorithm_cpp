#include <cmath>
#include <iostream>

using namespace std;

int c, n;
int people[20][100002];
int minPrice = 2000000000;
int info[20][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> c >> n;
	for (int i = 0; i < n; ++i) {
		cin >> info[i][0] >> info[i][1];
	}
	int price = info[0][0];
	int client = info[0][1];

	for (int j = price; j < minPrice; ++j) {
		people[0][j] = people[0][j - price] + client;
		if (people[0][j] >= c) {
			minPrice = j;
			break;
		}
	}

	for (int i = 1; i < n; ++i) {
		price = info[i][0];
		client = info[i][1];
		for (int j = 0; j < price; ++j) {
			people[i][j] = people[i - 1][j];
		}
		for (int j = price; j < minPrice; ++j) {
			people[i][j] = max(people[i][j - price] + client, people[i - 1][j]);
			if (people[i][j] >= c) {
				minPrice = j;
				break;
			}
		}
	}
	cout << minPrice << "\n";
	return 0;
}
#include <iostream>

using namespace std;

int n, m;
int preferences[30][30];
int result;
int pickedNumber[3];
bool included[30];

void getResult(int index, int depth) {
	if (depth == 3) {
		int tmpAnswer = 0;
		for (int i = 0; i < n; ++i) {
			int tmpMax = preferences[i][pickedNumber[0]];
			for (int j = 1; j < 3; ++j) {
				if (tmpMax < preferences[i][pickedNumber[j]]) {
					tmpMax = preferences[i][pickedNumber[j]];
				}
			}
			tmpAnswer += tmpMax;
		}
		if (tmpAnswer > result) {
			result = tmpAnswer;
		}
		return;
	}
	for (int i = index; i < m; ++i) {
		if (!included[i]) {
			pickedNumber[depth] = i;
			getResult(i + 1, depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> preferences[i][j];
		}
	}
	getResult(0, 0);
	cout << result << "\n";
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> friends(2000);

int n, m;
bool visited[2000];

void getInput() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
}

bool findFriend(int num, int depth) {
	if (depth == 5) {
		return true;
	}
	visited[num] = true;
	bool result = false;
	for (int person : friends[num]) {
		if (!visited[person]) {
			if (findFriend(person, depth + 1)) {
				return true;
			}
		}
	}
	visited[num] = false;
	return false;
}

int main() {
	getInput();
	char result = '0';
	for (int i = 0; i < n; ++i) {
		if (findFriend(i, 1)) {
			result = '1';
			break;
		}
	}
	cout << result << "\n";
}
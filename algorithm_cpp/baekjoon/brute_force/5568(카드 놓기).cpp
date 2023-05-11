#include <iostream>
#include <set>

using namespace std;

bool visited[10];
string nums[10];
set<string> s;
int n, k;

void findWays(string num, int depth) {
	if (depth == k) {
		if (s.find(num) == s.end()) {
			s.insert(num);
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			findWays(num + nums[i], depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	findWays("", 0);
	cout << s.size() << "\n";
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int n, m;

void findAnswer(string answer, int depth) {
	for (int i = 1; i <= n; ++i) {
		string str = to_string(i);
		if (depth == 1) {
			cout << answer + str << "\n";
		}
		else {
			findAnswer(answer + str + " ", depth - 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	findAnswer("", m);
	return 0;
}
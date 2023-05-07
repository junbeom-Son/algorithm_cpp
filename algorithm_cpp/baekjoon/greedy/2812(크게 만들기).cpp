#include <iostream>
#include <stack>

using namespace std;

stack<char> stk;
stack<char> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	string sNum;
	cin >> n >> k >> sNum;
	for (char c : sNum) {
		while (!stk.empty() && stk.top() < c && k > 0) {
			stk.pop();
			--k;
		}
		stk.push(c);
	}
	while (k > 0) {
		stk.pop();
		--k;
	}
	while (!stk.empty()) {
		answer.push(stk.top());
		stk.pop();
	}
	while (!answer.empty()) {
		cout << answer.top();
		answer.pop();
	}
	cout << "\n";
	return 0;
}

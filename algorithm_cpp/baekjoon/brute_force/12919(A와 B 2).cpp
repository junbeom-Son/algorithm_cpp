#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	queue<string> q;
	char result = '0';
	q.push(t);
	while (!q.empty()) {
		string front1 = q.front();
		string front2 = q.front();
		int length = front1.length();
		q.pop();
		if (front1 == s) {
			result = '1';
			break;
		}
		if (front1.size() == s.size()) {
			continue;
		}
		if (front1.at(0) == 'B') {
			front1 = front1.substr(1);
			reverse(front1.begin(), front1.end());
			q.push(front1);
		}
		if (front2.at(length - 1) == 'A') {
			front2 = front2.substr(0, length - 1);
			q.push(front2);
		}
	}
	cout << result << "\n";
	return 0;
}
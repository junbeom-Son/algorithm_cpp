#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	string expression;
	cin >> expression;
	int result = 0;
	queue<int> q;
	bool hasLeftNum = false;
	string strNum = "";
	int lastNum = 0;
	for (int i = 0; i < expression.length(); ++i) {
		char c = expression.at(i);
		if (c == '+') {
			int num = stoi(strNum);
			if (!hasLeftNum) {
				lastNum = num;
				hasLeftNum = true;
			}
			else {
				lastNum += num;

			}
			strNum = "";
		}
		else if (c == '-') {
			int num = stoi(strNum);
			if (hasLeftNum) {
				num += lastNum;
				hasLeftNum = false;
			}
			q.push(num);
			strNum = "";
		}
		else {
			strNum += c;
		}
	}
	int num = stoi(strNum);
	if (hasLeftNum) {
		num += lastNum;
	}
	q.push(num);
	result = q.front();
	q.pop();
	while (!q.empty()) {
		result -= q.front();
		q.pop();
	}
	cout << result << "\n";
	return 0;
}
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int n;
int numbers[101];
int answers[100];
int answerCount;
bool isAnswer[101];
stack<int> s;

bool findRightNumbers(int num, int initialNum) {
	s.push(num);
	isAnswer[num] = true;
	if (numbers[num] == initialNum) {
		return true;
	}
	if (isAnswer[numbers[num]]) {
		return false;
	}
	return findRightNumbers(numbers[num], initialNum);
}

void addAnswers() {
	while (!s.empty()) {
		int num = s.top();
		s.pop();
		answers[answerCount++] = num;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> numbers[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (i == numbers[i]) {
			answers[answerCount++] = i;
			isAnswer[i] = true;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!isAnswer[i] && findRightNumbers(i, i)) {
			addAnswers();
		}
		else {
			while (!s.empty()) {
				int num = s.top();
				s.pop();
				isAnswer[num] = false;
			}
		}
	}
	sort(answers, answers + answerCount);
	cout << answerCount << "\n";
	for (int i = 0; i < answerCount; ++i) {
		cout << answers[i] << "\n";
	}
	return 0;
}
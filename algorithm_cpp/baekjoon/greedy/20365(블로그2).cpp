#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string problems;
	cin >> problems;
	int solved = 0, unsolved = 0;
	char lastStatus = 'X';
	for (int i = 0; i < n; ++i) {
		char curStatus = problems.at(i);
		if (lastStatus != curStatus) {
			if (curStatus == 'B') {
				++solved;
			}
			else {
				++unsolved;
			}
			lastStatus = curStatus;
		}
	}
	int totalCount = solved + unsolved;
	if (totalCount > solved + 1) {
		totalCount = solved + 1;
	}
	if (totalCount > unsolved + 1) {
		totalCount = unsolved + 1;
	}
	cout << totalCount << "\n";
	return 0;
}
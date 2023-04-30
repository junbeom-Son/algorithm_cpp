#include <iostream>
#include <string>

using namespace std;

string n;
int minValue = INT_MAX;
int maxValue = -1;

int getOddCount(string s) {
	int result = 0;
	for (char c : s) {
		result += (c - '0') % 2;
	}
	return result;
}

void getCount(string s, int count) {
	int length = s.length();
	if (length >= 3) {
		for (int i = 1; i <= length - 2; ++i) {
			for (int j = i + 1; j <= length - 1; ++j) {
				int num1 = stoi(s.substr(0, i));
				int num2 = stoi(s.substr(i, j - i));
				int num3 = stoi(s.substr(j));
				string sNum = to_string(num1 + num2 + num3);
				getCount(sNum, count + getOddCount(sNum));
			}
		}
	}
	else if (length == 2) {
		int num1 = s.at(0) - '0';
		int num2 = s.at(1) - '0';
		string sNum = to_string(num1 + num2);
		getCount(sNum, count + getOddCount(sNum));
	}
	else {
		minValue = min(minValue, count + getOddCount(n));
		maxValue = max(maxValue, count + getOddCount(n));
	}
}

int main() {
	cin >> n;
	getCount(n, 0);
	cout << minValue << "\n" << maxValue << "\n";
	return 0;
}
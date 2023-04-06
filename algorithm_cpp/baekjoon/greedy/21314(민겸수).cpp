#include <iostream>
#include <string>

using namespace std;

string addStr(char c, int mCount) {
	string str = "";
	while (mCount > 0) {
		str += c;
		--mCount;
	}
	return str;
}
int main() {
	string maxStr = "", minStr = "";
	int mCount = 0;
	string Minkyeom;
	cin >> Minkyeom;


	for (int i = 0; i < Minkyeom.length(); ++i) {
		char c = Minkyeom.at(i);
		if (c == 'M') {
			++mCount;
		}
		else {
			maxStr += '5';
			maxStr += addStr('0', mCount);
			if (mCount > 0) {
				minStr += '1';
				minStr += addStr('0', mCount - 1);
			}
			minStr += '5';

			mCount = 0;
		}
	}
	if (Minkyeom.at(Minkyeom.length() - 1) == 'M') {
		maxStr += addStr('1', mCount);
		minStr += '1';
		minStr += addStr('0', mCount - 1);
	}
	cout << maxStr << "\n" << minStr << "\n";
	return 0;
}
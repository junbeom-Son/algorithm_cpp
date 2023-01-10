#include <iostream>
#include <string>

using namespace std;

string s;
int i = 0;

void printTag() {
	for (; s.at(i) != '>'; ++i) {
		cout << s.at(i);
	}
	cout << s.at(i);
}

void printReverseWord(int length) {
	string reversedWord = "";
	for (; i < length; ++i) {
		char curChar = s.at(i);
		if (curChar == ' ' || curChar == '<') {
			--i;
			break;
		}
		reversedWord += curChar;
	}
	for (int j = reversedWord.length() - 1; j >= 0; --j) {
		cout << reversedWord.at(j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	getline(cin, s);
	int length = (int)s.length();
	for (; i < length; ++i) {
		char curChar = s.at(i);
		if (curChar == '<') {
			printTag();
		}
		else if (curChar == ' ') {
			cout << curChar;
		}
		else {
			printReverseWord(length);
		}
	}
	return 0;
}
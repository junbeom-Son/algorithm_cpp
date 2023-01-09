#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string sound;
	cin >> sound;
	if ((int)sound.length() % 5 != 0 || sound.at(0) != 'q' || sound.at(sound.length() - 1) != 'k') {
		cout << -1 << "\n";
		return 0;
	}
	map<char, int> charCount;
	charCount['q'] = 0;
	charCount['u'] = 0;
	charCount['a'] = 0;
	charCount['c'] = 0;
	charCount['k'] = 0;
	bool impossible = false;
	for (int i = 0; i < (int)sound.length(); ++i) {
		char c = sound.at(i);
		if (c == 'q') {
			if (charCount['k'] > 0) {
				--charCount['q'];
				--charCount['u'];
				--charCount['a'];
				--charCount['c'];
				--charCount['k'];
			}
		}
		else if (c == 'u') {
			if (charCount['q'] <= charCount['u']) {
				impossible = true;
				break;
			}
		}
		else if (c == 'a') {
			if (charCount['u'] <= charCount['a']) {
				impossible = true;
				break;
			}
		}
		else if (c == 'c') {
			if (charCount['a'] <= charCount['c']) {
				impossible = true;
				break;
			}
		}
		else {
			if (charCount['c'] <= charCount['k']) {
				impossible = true;
				break;
			}
		}
		++charCount[c];
	}
	int num = charCount['q'];
	for (const auto& count : charCount) {
		if (num != count.second) {
			impossible = true;
			break;
		}
	}
	if (impossible) {
		num = -1;
	}
	cout << num << "\n";
	return 0;
}
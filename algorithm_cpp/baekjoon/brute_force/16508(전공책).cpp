#include <iostream>
#include <map>
#include <vector>
#define MAX 1000000000

using namespace std;

int minPrice = MAX;
int n;
string word;
vector<pair<int, map<char, int>>> v;
map<char, int> tmp;
map<char, int> target;

bool possibleBooks() {
	for (auto p : target) {
		char neededChar = p.first;
		int neededNum = p.second;
		if (tmp[neededChar] < neededNum) {
			return false;
		}
	}
	return true;
}

void addWord(int idx) {
	for (auto m : v[idx].second) {
		tmp[m.first] += m.second;
	}
}

void subtractWord(int idx) {
	for (auto m : v[idx].second) {
		tmp[m.first] -= m.second;
	}
}

void findResult(int idx, int price) {
	if (possibleBooks()) {
		if (price < minPrice) {
			minPrice = price;
		}
		return;
	}
	if (idx == n) {
		return;
	}
	for (int i = idx; i < n; ++i) {
		addWord(i);
		findResult(i + 1, price + v[i].first);
		subtractWord(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> word >> n;
	for (int i = 0; i < word.length(); ++i) {
		++target[word.at(i)];
	}
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> v[i].first >> tmp;
		int len = tmp.length();
		for (int j = 0; j < len; ++j) {
			++v[i].second[tmp.at(j)];
		}
	}
	findResult(0, 0);

	if (minPrice == MAX) {
		minPrice = -1;
	}
	cout << minPrice << "\n";
	return 0;
}
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

string getExtension(string fileName) {
	istringstream iss(fileName);
	string buffer;
	while (getline(iss, buffer, '.')) {

	}
	return buffer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	map<string, int> extensionCounts;
	vector<string> extensionNames;
	while (n > 0) {
		string fileName;
		cin >> fileName;
		string extensionName = getExtension(fileName);
		if (extensionCounts[extensionName] == 0) {
			extensionNames.push_back(extensionName);
			extensionCounts[extensionName] = 0;
		}
		++extensionCounts[extensionName];
		--n;
	}
	sort(extensionNames.begin(), extensionNames.end());
	for (string extensionName : extensionNames) {
		cout << extensionName << " " << extensionCounts[extensionName] << "\n";
	}
	return 0;
}
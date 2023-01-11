#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	int blocksHeight[500];
	int answer = 0;
	for (int i = 0; i < w; ++i) {
		cin >> blocksHeight[i];
	}
	for (int i = 1; i <= h; ++i) {
		vector<int> blocks;
		for (int j = 0; j < w; ++j) {
			if (blocksHeight[j] >= i) {
				blocks.push_back(j);
			}
		}
		if ((int)blocks.size() <= 1) {
			break;
		}
		for (int j = 1; j < (int)blocks.size(); ++j) {
			answer += blocks.at(j) - blocks.at(j - 1) - 1;
		}
	}
	cout << answer << "\n";
	return 0;
}
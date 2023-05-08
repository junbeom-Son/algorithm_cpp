#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> cranes;
vector<int> boxes;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cranes.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> cranes[i];
	}
	cin >> m;
	boxes.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> boxes[i];
	}
	sort(cranes.begin(), cranes.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());
	int result = 0;
	if (cranes[0] < boxes[0]) {
		result = -1;
		boxes.clear();
	}
	while (!boxes.empty()) {
		++result;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < boxes.size(); ++j) {
				if (cranes[i] >= boxes[j]) {
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
	}
	cout << result << "\n";
	return 0;
}
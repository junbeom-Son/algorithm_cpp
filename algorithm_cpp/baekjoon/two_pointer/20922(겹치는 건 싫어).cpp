#include <iostream>

using namespace std;

int n, k, longestLength = 0;
int nums[200000];
int counts[100001];

int findNextStartIndex(int startIndex, int index) {
	int num = nums[index];
	for (int i = startIndex; i <= index; ++i) {
		int curNum = nums[i];
		--counts[curNum];
		if (curNum == num) {
			return i + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	int startIndex = 0;

	for (int i = 0; i < n; ++i) {
		++counts[nums[i]];
		if (counts[nums[i]] > k) {
			int length = i - startIndex;
			if (length > longestLength) {
				longestLength = length;
			}
			startIndex = findNextStartIndex(startIndex, i);
		}
	}
	int length = n - startIndex;
	if (length > longestLength) {
		longestLength = length;
	}
	cout << longestLength << "\n";
	return 0;
}
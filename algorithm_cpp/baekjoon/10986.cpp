#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int* nums = new int[n + 1];
	map<int, int> subSum;
	nums[0] = 0;
	long long count = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> nums[i];
		nums[i] = (nums[i] + nums[i - 1]) % m;
		if (nums[i] == 0) {
			++count;
		}
		count += subSum[nums[i]];
		++subSum[nums[i]];
	}
	cout << count << "\n";
	return 0;
}
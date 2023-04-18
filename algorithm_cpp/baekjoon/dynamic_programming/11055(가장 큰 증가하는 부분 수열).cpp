#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[1000][2];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i][0];
	}
	arr[0][1] = arr[0][0];
	for (int i = 1; i < n; ++i) {
		arr[i][1] = arr[i][0];
		for (int j = i - 1; j >= 0; --j) {
			if (arr[j][0] < arr[i][0] && arr[j][1] + arr[i][0] > arr[i][1]) {
				arr[i][1] = arr[j][1] + arr[i][0];
			}
		}
	}
	int maxSum = arr[0][1];
	for (int i = 1; i < n; ++i) {
		if (arr[i][1] > maxSum) {
			maxSum = arr[i][1];

		}
	}
	cout << maxSum << "\n";
	return 0;
}
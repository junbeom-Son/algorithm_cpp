#include <iostream>

using namespace std;

int a[1000000];
int b[1000000];
int result[2000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int aIndex = 0, bIndex = 0, resultIndex = 0;
	while (aIndex < n && bIndex < m) {
		if (a[aIndex] < b[bIndex]) {
			result[resultIndex] = a[aIndex];
			++aIndex;
		}
		else {
			result[resultIndex] = b[bIndex];
			++bIndex;
		}
		++resultIndex;
	}
	while (aIndex < n) {
		result[resultIndex] = a[aIndex];
		++aIndex;
		++resultIndex;
	}
	while (bIndex < m) {
		result[resultIndex] = b[bIndex];
		++bIndex;
		++resultIndex;
	}
	for (int i = 0; i < n + m; ++i) {
		cout << result[i] << " ";
	}
	return 0;
}
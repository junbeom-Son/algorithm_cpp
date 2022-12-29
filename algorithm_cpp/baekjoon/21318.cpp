#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int* musics = new int[n + 1];
	int* mistakes = new int[n + 1];
	mistakes[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> musics[i];
	}
	for (int i = 1; i < n; ++i) {
		mistakes[i] = mistakes[i - 1];
		if (musics[i] > musics[i + 1]) {
			mistakes[i]++;
		}
	}
	int q;
	cin >> q;
	while (q > 0) {
		int x, y;
		cin >> x >> y;
		cout << mistakes[y - 1] - mistakes[x - 1] << "\n";
		--q;
	}
	return 0;
}
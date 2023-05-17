#include <iostream>
#include <iostream>

using namespace std;

int n;
int sour[10];
int bitter[10];
int s = 1, b = 0;
int answer = 2000000000;

void getResult(int index) {
	if (index == n) {
		return;
	}
	for (int i = index; i < n; ++i) {
		s *= sour[i];
		b += bitter[i];
		int diff = abs(s - b);
		if (diff < answer) {
			answer = diff;
		}
		getResult(i + 1);
		s /= sour[i];
		b -= bitter[i];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> sour[i] >> bitter[i];
	}
	getResult(0);
	cout << answer << "\n";
	return 0;
}
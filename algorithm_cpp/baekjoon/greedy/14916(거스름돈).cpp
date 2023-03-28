#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1 || n == 3) {
		cout << -1 << "\n";
		return 0;
	}
	int count = n / 5;
	int left = n % 5;
	if (left % 2 == 1) {
		--count;
		left += 5;
	}
	count += left / 2;
	cout << count << "\n";
	return 0;
}
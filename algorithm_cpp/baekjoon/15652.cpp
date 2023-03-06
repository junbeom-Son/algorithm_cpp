#include <iostream>
#include <string>

using namespace std;

int n, m;

void printResult(string result, int num, int depth) {
	for (int i = num; i <= n; ++i) {
		if (depth > 1) {
			printResult(result + to_string(i) + " ", i, depth - 1);
		}
		else {
			cout << result << to_string(i) << "\n";
		}
	}


}

int main() {
	cin >> n >> m;
	printResult("", 1, m);
	return 0;
}
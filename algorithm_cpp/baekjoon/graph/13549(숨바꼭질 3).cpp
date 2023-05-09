#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 150000
using namespace std;

int times[MAX];
queue<int> q;

void calculateTime(int departure, int destination, int diff) {
	if (destination >= MAX) {
		return;
	}
	if (times[destination] == -1 || times[departure] + diff < times[destination]) {
		times[destination] = times[departure] + diff;
		q.push(destination);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	fill_n(times, MAX, -1);

	q.push(n);
	times[n] = 0;
	while (true) {
		int position = q.front();
		q.pop();
		if (position == k) {
			break;
		}
		calculateTime(position, position * 2, 0);
		calculateTime(position, position - 1, 1);
		calculateTime(position, position + 1, 1);
	}
	cout << times[k] << "\n";
	return 0;
}
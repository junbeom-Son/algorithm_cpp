/*
* 1. yPrime을 첫 x값을 기준으로 설정한다.
* 2. yPrime이 N과 일치하거나, 혹은 M * N크기의 순서가 올때까지 반복한다.
*   2-1. yPrime을 M크기 만큼 더한 후의 값을 구한다.
*   2-2. 순서를 M 만큼 증가시킨다.
* 3. 순서가 M * N 이하이면 순서를 출력하고, 이상이면 -1을 출력한다.
*/

#include <algorithm>
#include <iostream>

using namespace std;

int calculateYPrime(int N, int yPrime) {
	yPrime = yPrime % N;
	if (yPrime == 0) {
		yPrime = N;
	}
	return yPrime;
}

int getMaxYear(int M, int N) {
	int biggerNum = max(M, N);
	int maxYear = biggerNum;
	int smallerNum = min(M, N);
	while (maxYear % smallerNum != 0) {
		maxYear += biggerNum;
	}
	return maxYear;
}

int getYear(int M, int N, int x, int y) {
	int yPrime = calculateYPrime(N, x);
	int year = x;
	int maxYear = getMaxYear(M, N);
	while (year < maxYear && yPrime != y) {
		yPrime = calculateYPrime(N, yPrime + M);
		year += M;
	}
	if (y != yPrime) {
		year = -1;
	}
	return year;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t > 0) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		cout << getYear(M, N, x, y) << "\n";
		--t;
	}
	return 0;
}
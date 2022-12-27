/*
* 1. yPrime�� ù x���� �������� �����Ѵ�.
* 2. yPrime�� N�� ��ġ�ϰų�, Ȥ�� M * Nũ���� ������ �ö����� �ݺ��Ѵ�.
*   2-1. yPrime�� Mũ�� ��ŭ ���� ���� ���� ���Ѵ�.
*   2-2. ������ M ��ŭ ������Ų��.
* 3. ������ M * N �����̸� ������ ����ϰ�, �̻��̸� -1�� ����Ѵ�.
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
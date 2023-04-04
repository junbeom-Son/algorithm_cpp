#include <iostream>

using namespace std;

int arr[20];
int n, s;
int totalCount = 0;

// index : 현재 접근한 숫자가 몇번째 숫자인지
// prefixSum : 현재까지 집계된 부분 합
// includeCount : 현재까지 포함된 숫자의 개수 
//   -> 끝까지 아무 숫자도 포함되지 않는다면 count를 추가하지 않는다.

void getResult(int index, int prefixSum, int includedCount) {
	if (index == n) { // 모든 숫자를 거치고 났다면
		if (s == prefixSum && includedCount > 0) {
			// 숫자를 더한 값이 목표인 s와 같고, 숫자를 한개 이상 포함했다면 하나 카운트한다.
			++totalCount;
		}
		return;
	}
	getResult(index + 1, prefixSum + arr[index], includedCount + 1); // index번째 숫자를 포함하는 경우
	getResult(index + 1, prefixSum, includedCount); // index번째 숫자를 포함하지 않는 경우
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	getResult(0, 0, 0);
	cout << totalCount << "\n";
	return 0;
}
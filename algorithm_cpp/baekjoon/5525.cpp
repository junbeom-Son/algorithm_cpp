/*
* I와 O로만 이루어진 문자열을 가지고 패턴을 가진 문자열이 몇개 나오는지 새는 프로그램
* index 2 부터 n - 1까지의 문자들을 순회
* 1. 현재 위치의 문자가 I라면
* 2. 현재 위치 - 1의 문자가 O이고 현재 위치의 - 2의 문자가 I인지 확인한다.
* 2-1. 조건을 충족한다면 현재위치 - 2의 위치의 카운트 + 1을 센다.
* 3. 카운트를 저장한 배열을 순회하며 n 이상이 저장된 곳들의 숫자를 센 후 출력한다.
*/
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	string IOString;
	cin >> IOString;
	int* patternCounts = new int[m];
	for (int i = 0; i < m; ++i) {
		patternCounts[i] = 0;
	}
	for (int i = 2; i < m; ++i) {
		if (IOString.at(i) == 'I' && IOString.at(i - 1) == 'O' && IOString.at(i - 2) == 'I') {
			patternCounts[i] = patternCounts[i - 2] + 1;
		}
	}
	int result = 0;
	for (int i = 0; i < m; ++i) {
		if (patternCounts[i] >= n) {
			++result;
		}
	}
	cout << result << "\n";
	return 0;
}
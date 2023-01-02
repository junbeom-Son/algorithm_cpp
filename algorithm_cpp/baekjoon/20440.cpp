/*
* 1. 모기의 입장시각 정렬
* 2. 모기의 퇴장시각 정렬
* 3. 임의의 모기A의 입장시각과 임의의 모기B의 퇴장시각이 같다면 다음 모기 대기
* 4. 모기가 입장하면 모기 카운트 1 증가
* 4-1. 모기가 입장할 때 이전 최대 모기 수보다 많다면 최대 모기수 및 당시 시각 기록
* 5. 모기가 퇴장할때 현재 모기수가 최대 모기수 이고 최대 모기수 입장 시각을 기록하고 있다면
* 5-1. 최대 모기수 퇴장 시각 기록
* 5-2. 모기 카운트 1 감소
* 6. 최대 모기수와 최대 모기수가 있는 시간대 출력
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int* entryTimes = new int[n];
	int* exitTimes = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> entryTimes[i];
		cin >> exitTimes[i];
	}
	sort(entryTimes, entryTimes + n);
	sort(exitTimes, exitTimes + n);
	int maxCount = 0;
	int count = 0;
	int maxTimeStart = 0;
	int maxTimeEnd = 0;
	int admittanceCount = 0;
	int exitCount = 0;
	bool startTimeCount = false;
	while (admittanceCount < n) {
		if (exitTimes[exitCount] == entryTimes[admittanceCount]) {
			++exitCount;
			++admittanceCount;
		}
		else if (exitTimes[exitCount] < entryTimes[admittanceCount]) {
			if (count == maxCount && startTimeCount) {
				startTimeCount = false;
				maxTimeEnd = exitTimes[exitCount];
			}
			--count;
			++exitCount;
		}
		else {
			++count;
			if (count > maxCount) {
				maxCount = count;
				maxTimeStart = entryTimes[admittanceCount];
				startTimeCount = true;
			}
			++admittanceCount;
		}
	}
	if (startTimeCount) {
		maxTimeEnd = exitTimes[exitCount];
	}
	cout << maxCount << "\n";
	cout << maxTimeStart << " " << maxTimeEnd << "\n";
	return 0;
}
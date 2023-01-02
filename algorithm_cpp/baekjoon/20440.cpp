/*
* 1. ����� ����ð� ����
* 2. ����� ����ð� ����
* 3. ������ ���A�� ����ð��� ������ ���B�� ����ð��� ���ٸ� ���� ��� ���
* 4. ��Ⱑ �����ϸ� ��� ī��Ʈ 1 ����
* 4-1. ��Ⱑ ������ �� ���� �ִ� ��� ������ ���ٸ� �ִ� ���� �� ��� �ð� ���
* 5. ��Ⱑ �����Ҷ� ���� ������ �ִ� ���� �̰� �ִ� ���� ���� �ð��� ����ϰ� �ִٸ�
* 5-1. �ִ� ���� ���� �ð� ���
* 5-2. ��� ī��Ʈ 1 ����
* 6. �ִ� ������ �ִ� ������ �ִ� �ð��� ���
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
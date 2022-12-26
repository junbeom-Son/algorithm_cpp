/*
* I�� O�θ� �̷���� ���ڿ��� ������ ������ ���� ���ڿ��� � �������� ���� ���α׷�
* index 2 ���� n - 1������ ���ڵ��� ��ȸ
* 1. ���� ��ġ�� ���ڰ� I���
* 2. ���� ��ġ - 1�� ���ڰ� O�̰� ���� ��ġ�� - 2�� ���ڰ� I���� Ȯ���Ѵ�.
* 2-1. ������ �����Ѵٸ� ������ġ - 2�� ��ġ�� ī��Ʈ + 1�� ����.
* 3. ī��Ʈ�� ������ �迭�� ��ȸ�ϸ� n �̻��� ����� ������ ���ڸ� �� �� ����Ѵ�.
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
#include <iostream>

using namespace std;

int arr[20];
int n, s;
int totalCount = 0;

// index : ���� ������ ���ڰ� ���° ��������
// prefixSum : ������� ����� �κ� ��
// includeCount : ������� ���Ե� ������ ���� 
//   -> ������ �ƹ� ���ڵ� ���Ե��� �ʴ´ٸ� count�� �߰����� �ʴ´�.

void getResult(int index, int prefixSum, int includedCount) {
	if (index == n) { // ��� ���ڸ� ��ġ�� ���ٸ�
		if (s == prefixSum && includedCount > 0) {
			// ���ڸ� ���� ���� ��ǥ�� s�� ����, ���ڸ� �Ѱ� �̻� �����ߴٸ� �ϳ� ī��Ʈ�Ѵ�.
			++totalCount;
		}
		return;
	}
	getResult(index + 1, prefixSum + arr[index], includedCount + 1); // index��° ���ڸ� �����ϴ� ���
	getResult(index + 1, prefixSum, includedCount); // index��° ���ڸ� �������� �ʴ� ���
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
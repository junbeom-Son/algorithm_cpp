/*
* ���� ���� �⼮�� �л� �� ���ϱ�
* �Է� : �л� �� N, ���� �ִ� �л� �� K, ��ȯ�� �⼮ �ڵ带 ���� �л� �� Q, �־��� ������ �� M,
*        K���� ���� �ִ� �л��� ���� ��ȣ��, Q���� �⼮ �ڵ带 ���� �л��� ���� ��ȣ��,
*        M���� ����(S, E)
* ��� : M���� �ٿ� ���ļ� �� ������ ���ؼ� �⼮�� ���� ���� �л����� �� ���
* 1. �л��� �� + 3 ���� ��ŭ�� �⼮���� �迭 1�� �ʱ�ȭ(0 - �⼮, 1 - �⼮x)
* 2. �л��� �� + 3 ���� ��ŭ�� ���� �ִ� �л� �迭 false�� �ʱ�ȭ ��, �ڴ� ģ���� ��ȣ�� true
* 3. ��ȯ���� ���� �⼮ �ڵ带 ���� Q���� �л� �Է� ��, ������ �л����� ���� �ִ� �л��� ������ �ڽ��� ��ȣ�� ������� �л��鿡�� �⼮�ڵ� ����
* 4. �⼮ ���� �迭�� ���� ���� ���� �л���ȣ �� �⼮ �ڵ带 ���� �л����� ��� 0���� �� ����(üũ ���� ���� �л��� ���� ���� �ϱ� ������ �����ϱ� ����)
* 5. �⼮ ���� �迭�� ������ ���
* 6. M���� ���� �Է�(S ~ E)
* 6-1. S ~ E �������� �⼮üũ ���� ���� �л��� �� ����� ���
*/

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, Q, M;
	cin >> N >> K >> Q >> M;
	N += 2;
	int* uncheckedStudents = new int[N + 1]();
	bool* sleepingStudents = new bool[N + 1]();
	uncheckedStudents[2] = 0;
	for (int i = 3; i <= N; ++i) {
		uncheckedStudents[i] = 1;
		sleepingStudents[i] = false;
	}
	while (K > 0) {
		int sleepingStudent;
		cin >> sleepingStudent;
		sleepingStudents[sleepingStudent] = true;
		--K;
	}
	while (Q > 0) {
		int presentStudent;
		cin >> presentStudent;
		if (!sleepingStudents[presentStudent]) {
			for (int i = presentStudent; i <= N; i += presentStudent) {
				if (!sleepingStudents[i]) {
					uncheckedStudents[i] = 0;
				}
			}
		}
		--Q;
	}
	for (int i = 3; i <= N; ++i) {
		uncheckedStudents[i] += uncheckedStudents[i - 1];
	}
	while (M > 0) {
		int S, E;
		cin >> S >> E;
		cout << uncheckedStudents[E] - uncheckedStudents[S - 1] << "\n";
		--M;
	}
	delete[] uncheckedStudents;
	delete[] sleepingStudents;
	return 0;
}
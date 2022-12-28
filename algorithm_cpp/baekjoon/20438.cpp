/*
* 범위 내의 출석한 학생 수 구하기
* 입력 : 학생 수 N, 졸고 있는 학생 수 K, 지환이 출석 코드를 보낼 학생 수 Q, 주어질 구간의 수 M,
*        K명의 졸고 있는 학생의 입장 번호들, Q명의 출석 코드를 받을 학생의 입장 번호들,
*        M개의 범위(S, E)
* 출력 : M개의 줄에 걸쳐서 각 구간에 대해서 출석이 되지 않은 학생들의 수 출력
* 1. 학생의 수 + 3 길이 만큼의 출석여부 배열 1로 초기화(0 - 출석, 1 - 출석x)
* 2. 학생의 수 + 3 길이 만큼의 졸고 있는 학생 배열 false로 초기화 후, 자는 친구의 번호만 true
* 3. 지환에게 직접 출석 코드를 받은 Q명의 학생 입력 후, 각각의 학생들은 졸고 있는 학생을 제외한 자신의 번호의 배수들의 학생들에게 출석코드 전달
* 4. 출석 여부 배열의 졸고 있지 않은 학생번호 중 출석 코드를 받은 학생들은 모두 0으로 값 변경(체크 되지 않은 학생의 수를 세야 하기 때문에 제외하기 위함)
* 5. 출석 여부 배열의 누적합 계산
* 6. M번의 범위 입력(S ~ E)
* 6-1. S ~ E 범위내의 출석체크 되지 않은 학생의 수 계산후 출력
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
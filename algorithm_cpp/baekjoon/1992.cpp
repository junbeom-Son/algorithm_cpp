/*
* 1. ���� ���� ������ ��� ���� �������� �˻�
* 2. ���� ���� ������ ��� ���� �ʴٸ�, '(�� ����ϰ� ������ 4���� �ɰ��� 1.�� �ٽ� �����Ѵ�. �����Ŀ� ')'�� �߰��� ����Ѵ�.
*/

#include <iostream>
#include <vector>

void pressVideo(int top, int left, int bottom, int right);
bool isPressed(int top, int left, int bottom, int right);

using namespace std;

vector<string> video;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string row;
		cin >> row;
		video.push_back(row);
	}
	pressVideo(0, 0, N, N);
	return 0;
}

void pressVideo(int top, int left, int bottom, int right) {
	if (isPressed(top, left, bottom, right)) {
		cout << video[top].at(left);
	}
	else {
		cout << "(";
		pressVideo(top, left, (top + bottom) / 2, (left + right) / 2);
		pressVideo(top, (left + right) / 2, (top + bottom) / 2, right);
		pressVideo((top + bottom) / 2, left, bottom, (left + right) / 2);
		pressVideo((top + bottom) / 2, (left + right) / 2, bottom, right);
		cout << ")";
	}
}

bool isPressed(int top, int left, int bottom, int right) {
	if (top == bottom) {
		return true;
	}
	char color = video[top].at(left);
	for (int i = top; i < bottom; ++i) {
		for (int j = left; j < right; ++j) {
			if (color != video[i].at(j)) {
				return false;
			}
		}
	}
	return true;
}
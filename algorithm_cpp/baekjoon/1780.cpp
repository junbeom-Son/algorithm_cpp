// 1. ���� ���� ��� ������ ���� ������ Ȯ���Ѵ�.
// 2-1. �������̶�� �ش� ���� ������ ����.
// 2-2. �������� �ƴ϶�� 9���� �������� ������ 1�� �ٽ� �����Ѵ�.
// 3. ������ ���� ����Ѵ�.

#include <iostream>
#include <vector>

void countColors(int top, int left, int bottom, int right);
bool isSameColors(int top, int left, int bottom, int right);

using namespace std;

int numOfPapers[3] = { 0, 0, 0 };
int rows[3][2] = { {0, 1}, {1, 2}, {2, 3} };
int cols[3][2] = { {0, 1}, {1, 2}, {2, 3} };
vector<vector<int>> paper;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        vector<int> row;
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            row.push_back(++num);
        }
        paper.push_back(row);
    }
    countColors(0, 0, N, N);
    for (int i = 0; i < 3; ++i) {
        cout << numOfPapers[i] << "\n";
    }
    return 0;
}

void countColors(int top, int left, int bottom, int right) {
    if (top == bottom) {
        numOfPapers[paper[top][left]]++;
        return;
    }
    if (isSameColors(top, left, bottom, right)) {
        numOfPapers[paper[top][left]]++;
    }
    else {
        int length = (right - left) / 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                countColors(top + (length * rows[i][0]), left + (length * cols[j][0]),
                    top + (length * rows[i][1]), left + (length * cols[j][1]));
            }
        }
    }
}

bool isSameColors(int top, int left, int bottom, int right) {
    int color = paper[top][left];
    for (int i = top; i < bottom; ++i) {
        for (int j = left; j < right; ++j) {
            if (color != paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}
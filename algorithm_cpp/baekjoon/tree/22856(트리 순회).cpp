#include <iostream>

using namespace std;

int tree[100001][3]; // left, right, parent
int n;
bool visited[100001];

bool isFinalOrder(int visitCount, int curNode) {
	if (visitCount != n) {
		return false;
	}
	while (curNode != 1) {
		int parent = tree[curNode][2];
		if (curNode != tree[parent][1]) {
			return false;
		}
		curNode = parent;
	}
	return true;
}

long long traversal() {
	if (n == 1) {
		return 0;
	}
	long long total = 0;
	int curNode = 1;
	int visitCount = 0;
	tree[0][1] = 1;
	while (true) {
		int leftChild = tree[curNode][0];
		int rightChild = tree[curNode][1];
		int parent = tree[curNode][2];
		if (!visited[curNode]) {
			visited[curNode] = true;
			++visitCount;
		}
		if (leftChild != -1 && !visited[leftChild]) { // ���� �ڽ��� �ְ�, �湮������ ���ٸ�
			tree[leftChild][2] = curNode;
			curNode = leftChild;
		}
		else if (rightChild != -1 && !visited[rightChild]) { // ������ �ڽ��� �ְ�, �湮������ ���ٸ�
			tree[rightChild][2] = curNode;
			curNode = rightChild;
		}
		else if (isFinalOrder(visitCount, curNode)) { // �� �湮�߰�, ���� ������ �ڽ��̶�� (Ʈ���� ������ �����̶��)
			break;
		}
		else {
			curNode = parent;
		}
		++total;
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int parent, leftChild, rightChild;
		cin >> parent >> leftChild >> rightChild;
		tree[parent][0] = leftChild;
		tree[parent][1] = rightChild;
	}
	cout << traversal() << "\n";
	return 0;
}
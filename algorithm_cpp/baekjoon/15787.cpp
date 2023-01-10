#include <algorithm>
#include <iostream>
#define MAX_PASSENGER_NUM 20
#define MAX_TRAIN_NUM 100000

using namespace std;

int n, m;
bool train[MAX_TRAIN_NUM + 1][MAX_PASSENGER_NUM + 1];

bool isRecorded(int compartmentNum) {
	for (int i = 1; i < compartmentNum; ++i) {
		bool recorded = true;
		for (int j = 1; j <= 20; ++j) {
			if (train[i][j] != train[compartmentNum][j]) {
				recorded = false;
				break;
			}
		}
		if (recorded) {
			return true;
		}
	}
	return false;
}

void command1(int compartmentNum, int passengerNum) {
	train[compartmentNum][passengerNum] = true;
}

void command2(int compartmentNum, int passengerNum) {
	train[compartmentNum][passengerNum] = false;
}

void command3(int compartmentNum) {
	for (int i = MAX_PASSENGER_NUM; i >= 1; --i) {
		train[compartmentNum][i] = train[compartmentNum][i - 1];
	}
}

void command4(int compartmentNum) {
	for (int i = 1; i < MAX_PASSENGER_NUM; ++i) {
		train[compartmentNum][i] = train[compartmentNum][i + 1];
	}
	train[compartmentNum][MAX_PASSENGER_NUM] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fill(train[i], train[i] + MAX_PASSENGER_NUM + 1, false);
	}
	while (m > 0) {
		int command, compartmentNum, passengerNum = 0;
		cin >> command >> compartmentNum;
		if (command == 1 || command == 2) {
			cin >> passengerNum;
		}
		switch (command) {
		case 1:
			command1(compartmentNum, passengerNum);
			break;
		case 2:
			command2(compartmentNum, passengerNum);
			break;
		case 3:
			command3(compartmentNum);
			break;
		case 4:
			command4(compartmentNum);
			break;
		}
		--m;
	}
	int count = 1;
	for (int i = 2; i <= n; ++i) {
		if (!isRecorded(i)) {
			++count;
		}
	}
	cout << count << "\n";
	return 0;
}
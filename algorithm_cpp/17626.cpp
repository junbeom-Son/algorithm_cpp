#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int No17626()
{
    int n;
    cin >> n;
    int* nums = new int[n + 1];
    fill_n(nums, n + 1, 0);
    nums[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int minNum = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            int tmp = i - j * j;
            minNum = min(minNum, nums[tmp]);
        }
        nums[i] = minNum + 1;
    }
    cout << nums[n];
    delete[] nums;
    return 0;
}
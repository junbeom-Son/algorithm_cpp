#include <iostream>
#include <string>

using namespace std;

int n, m;

void findAnswer(string answer, int depth, int num) {
    if (n - num + 1 < depth) {
        return;
    }
    for (int i = num + 1; i <= n; ++i) {
        if (depth > 1) {
            findAnswer(answer + to_string(i) + " ", depth - 1, i);
        }
        else {
            cout << answer + to_string(i) + " " + "\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    findAnswer("", m, 0);
    return 0;
}
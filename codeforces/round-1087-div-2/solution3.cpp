#include <iostream>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n))
        return;

    auto query = [&](int i, int j) {
        cout << "? " << i << " " << j << endl;
        int ans;
        cin >> ans;
        if (ans == -1) {
            exit(0);
        }
        return ans;
    };

    // 1. 獨立對
    // (4,5),(6,7),...
    // 最多查詢n-2次，最多只有n-2個0
    for (int i = 4; i < 2 * n; i += 2) {
        if (query(i, i + 1) == 1) {
            cout << "! " << i << endl;
            return;
        }
    }

    // 2. 三角形
    // 最壞狀況：1!=2,2!=3,1!=3，則易得1!=2!=3，最多只有一個0
    if (query(1, 2) == 1) {
        cout << "! 1" << endl;
        return;
    }
    if (query(2, 3) == 1) {
        cout << "! 2" << endl;
        return;
    }
    if (query(1, 3) == 1) {
        cout << "! 3" << endl;
        return;
    }

    // 3. 確認了前面最多n-1個0，所以最後一個必須是0
    cout << "! " << 2 * n << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

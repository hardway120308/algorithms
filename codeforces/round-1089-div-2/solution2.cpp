#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int my_ans = 0;
        bool marked[n];
        memset(marked, 0, sizeof(marked));
        for (int i = 0; i < n; i++) {
            // 動作
            // 1. 做下一個標記的椅子
            // 2. 坐下並標記p[i]椅子
            // 3. 跳過目前椅子
            // 儘可能延後遇到marked的時間
            if ((p[i] - 1) <= i) {
                my_ans++;
            } else {
                // skip
            }
        }
        cout << my_ans << endl;
    }
}

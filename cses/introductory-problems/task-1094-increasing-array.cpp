#include <bits/stdc++.h>
#define int long long

using namespace std;

// 貪心
signed main() {
    int n;
    cin >> n;
    int x[n];
    int min_moves = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (i >= 1) {
            int before = x[i - 1];
            if (x[i] >= before) {
                // 不用做事
                continue;
            } else {
                min_moves += (abs(x[i] - before));
                x[i] = before;
            }
        }
    }
    cout << min_moves << endl;
}

#include <bits/stdc++.h>
#include <string>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;

    int a[n];
    const int L = 1000000;

    int b[L];
    memset(b, 0, sizeof(b));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // 尾端+1
        b[L - 1]++;
        // 開端後一位-1
        b[L - a[i] - 1]--;
    }
    int fix = 0;
    int digit = 0;
    string ans;
    for (int i = L - 1; i >= 0; i--) {
        // 差分
        digit += b[i];
        int now_d = digit + fix;
        if (now_d >= 10) {
            fix = now_d / 10;
            ans += to_string(now_d % 10);
        } else {
            ans += to_string(now_d);
            fix = 0;
        }
    }

    bool start_say = false;
    for (int i = ans.length() - 1; i >= 0; i--) {
        if (ans[i] != '0') {
            start_say = true;
        }
        if (start_say) {
            cout << ans[i];
        }
    }
}

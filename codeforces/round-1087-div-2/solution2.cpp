#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
        }

        for (int i = 0; i < n; i++) {
            int ans_1 = 0;
            int ans_2 = 0;
            // 找到a_i-k > aj - k，k爲任意數
            for (int j = n - 1; j >= i + 1; j--) {
                if (a[j] > a[i]) {
                    ans_1++;
                } else if (a[j] == a[i]) {
                    continue;
                } else {
                    ans_2++;
                }
            }
            cout << max(ans_1, ans_2) << " ";
        }
        cout << endl;
    }
}

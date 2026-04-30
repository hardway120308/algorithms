#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    vector<vector<int>> pos(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    // 0 必須在回文中，對稱中心 S 只有這三種可能
    vector<long long> candidates = {(long long)pos[0][0] + pos[0][1], 2LL * pos[0][0], 2LL * pos[0][1]};

    int max_mex = 0;

    for (long long S : candidates) {
        if (S < 0 || S > 2LL * (m - 1))
            continue;

        vector<int> is_bad(m, 0);
        for (int i = 0; i < m; ++i) {
            int v = a[i];
            if (S % 2 == 0 && i == S / 2)
                continue;
            if ((long long)pos[v][0] + pos[v][1] != S) {
                is_bad[i] = 1;
            }
        }

        vector<int> pref(m + 1, 0);
        for (int i = 0; i < m; ++i)
            pref[i + 1] = pref[i] + is_bad[i];

        int L = m, R = -1;
        for (int k = 0; k < n; ++k) {
            if (S % 2 == 0 && (pos[k][0] == S / 2 || pos[k][1] == S / 2)) {
                L = min(L, (int)(S / 2));
                R = max(R, (int)(S / 2));
            } else if ((long long)pos[k][0] + pos[k][1] == S) {
                L = min({L, pos[k][0], pos[k][1]});
                R = max({R, pos[k][0], pos[k][1]});
            } else {
                break;
            }

            int L_sym = min(L, (int)(S - R));
            int R_sym = max(R, (int)(S - L));

            if (L_sym < 0 || R_sym >= m)
                break;

            if (pref[R_sym + 1] - pref[L_sym] == 0) {
                if (S % 2 == 0) {
                    int center_val = a[S / 2];
                    int other = (pos[center_val][0] == S / 2) ? pos[center_val][1] : pos[center_val][0];
                    if (other < L_sym || other > R_sym) {
                        max_mex = max(max_mex, k + 1);
                    }
                } else {
                    max_mex = max(max_mex, k + 1);
                }
            }
        }
    }
    cout << max_mex << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

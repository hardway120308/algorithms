#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool ok = true;

        // Step 1: check duplicates in b
        vector<bool> seen(n + 1, false);
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                if (seen[b[i]]) {
                    ok = false;
                    break;
                }
                seen[b[i]] = true;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        // Case 1: 2k <= n
        if (2 * k <= n) {
            for (int i = 0; i < n; i++) {
                if (b[i] != -1 && b[i] != a[i]) {
                    ok = false;
                    break;
                }
            }
        }
        // Case 2: 2k > n
        else {
            // prefix [0, n-k-1]
            for (int i = 0; i < n - k; i++) {
                if (b[i] != -1 && b[i] != a[i]) {
                    ok = false;
                    break;
                }
            }

            // suffix [k, n-1]
            for (int i = k; i < n && ok; i++) {
                if (b[i] != -1 && b[i] != a[i]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) {
                cout << "NO\n";
                continue;
            }

            // middle [n-k, k-1]
            vector<bool> in_middle(n + 1, false);

            for (int i = n - k; i < k; i++) {
                in_middle[a[i]] = true;
            }

            for (int i = n - k; i < k; i++) {
                if (b[i] != -1 && !in_middle[b[i]]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

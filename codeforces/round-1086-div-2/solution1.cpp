#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int, int> cnt;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                cnt[x]++;
                if (cnt[x] > n * n - n)
                    ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}

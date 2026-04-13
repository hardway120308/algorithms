#include <bits/stdc++.h>

using namespace std;

void solve() {}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_consecutive = 1;
        int current_consecutive = 1;

        // Count the maximum number of contiguous identical elements
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                current_consecutive++;
            } else {
                if (current_consecutive > max_consecutive) {
                    max_consecutive = current_consecutive;
                }
                current_consecutive = 1;
            }
        }
        // Final check for the last block
        if (current_consecutive > max_consecutive) {
            max_consecutive = current_consecutive;
        }

        // If there's a block of `m` or more synced volunteers, he is blocked.
        if (max_consecutive >= m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}

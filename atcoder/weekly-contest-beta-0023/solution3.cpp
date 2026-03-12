#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long int t[n];
    long long prefix_sum_t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    prefix_sum_t[0] = t[0];
    for (int i = 1; i < n; i++) {
        prefix_sum_t[i] = prefix_sum_t[i - 1] + t[i];
    }
    for (int i = 0; i < m; i++) {
        // [l,r]區間
        long long int s;
        int l, r;
        cin >> s >> l >> r;

        if (l == 1) {
            long long int time = s + prefix_sum_t[r - 1];
            cout << time << endl;
        } else {
            long long int time = s + prefix_sum_t[r - 1] - prefix_sum_t[l - 2];
            cout << time << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prime_list() {
    vector<int> res;
    vector<bool> is_prime(200000, true);
    for (int p = 2; res.size() < 10007; p++) {
        if (is_prime[p]) {
            res.push_back(p);
            for (int i = 2 * p; i < 200000; i += p)
                is_prime[i] = false;
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> P = prime_list();

        for (int i = 0; i < n; i++) {
            // Pi*Pi+1
            cout << P[i] * P[i + 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}

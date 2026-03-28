#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;
}

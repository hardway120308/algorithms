#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i * k <= n; i++) {
        cout << a[i * k - 1] << " ";
    }
    return 0;
}

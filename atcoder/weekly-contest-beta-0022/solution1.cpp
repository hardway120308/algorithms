#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, d, k;
    long long int ans = 0;
    cin >> n >> d >> k;
    for (int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        if ((x - d * k) >= 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    int ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int p;
            cin >> p;
            if (p >= k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

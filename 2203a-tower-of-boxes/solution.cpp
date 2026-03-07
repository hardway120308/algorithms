#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (--testcases) {
        int n, m, d;
        int ans = 0;
        cin >> n >> m >> d;
        int all_weight = n * m;
        int des = 0;
        while (all_weight > 0) {
            for (int i = 0; i <= n; i++) {
                if (i * m < d) {
                    if (i == n - 1) {
                        ans = 1;
                        all_weight -= n * m;
                        break;
                    }
                    continue;
                } else if (i * m == d) {
                    all_weight -= (i + 1) * m;
                    ans++;
                    break;
                } else {
                    all_weight -= i * m;
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    int c[n + 1][n + 1];
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    // print c
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i + 1; k <= j - 1; k++) {
                if (i != j and c[i][j] != 0 and c[i][k] != 0 and c[k][j] != 0) {
                    if (c[i][k] + c[k][j] < c[i][j]) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x;
    int ans = 0;
    cin >> a >> b >> c >> x;
    for (int i = 0; i <= a; i++) {
        if (i * 500 > x)
            break;
        for (int j = 0; j <= b; j++) {
            if (j * 100 > x)
                break;
            for (int k = 0; k <= c; k++) {
                if (k * 50 > x)
                    break;
                if (i * 500 + j * 100 + k * 50 == x) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

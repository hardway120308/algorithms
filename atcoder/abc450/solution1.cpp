#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        if (i != 1) {
            cout << i << ",";
        } else {
            cout << i;
        }
    }
    return 0;
}

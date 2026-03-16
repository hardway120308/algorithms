#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;

    int takashi, aoki;
    takashi = 0;
    aoki = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (takashi + value <= k) {
            takashi += value;
        } else {
            aoki += value;
        }
    }
    if (takashi > aoki) {
        cout << "Takahashi" << endl;
    } else if (aoki > takashi) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}

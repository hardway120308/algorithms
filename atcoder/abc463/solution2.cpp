#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    char x;
    cin >> n >> x;
    string s[n];
    bool ans = false;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][x - 'A'] == 'o') {
            ans = true;
            break;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

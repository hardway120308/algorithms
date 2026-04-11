#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    string s;
    bool start_say = false;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (not start_say) {
            if (s[i] == 'o') {
                continue;
            } else {
                start_say = true;
                cout << s[i];
            }
        } else {
            cout << s[i];
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int left_num = 0;
        int right_num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left_num++;
            } else {
                right_num++;
            }
        }
        if (left_num == right_num) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

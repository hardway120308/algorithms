#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;
    int now_max_repetition = 0;
    int now_repetition = 0;
    char now_char = s[0];
    for (int i = 0; i < s.length(); i++) {
        if (now_char == s[i]) {
            now_repetition++;
        } else {
            now_max_repetition = max(now_repetition, now_max_repetition);
            now_repetition = 1;
            now_char = s[i];
        }
    }
    now_max_repetition = max(now_repetition, now_max_repetition);
    cout << now_max_repetition << endl;
}

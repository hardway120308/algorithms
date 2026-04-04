#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int m;
    cin >> m;
    string s[m];
    map<int, vector<string>> STRING_BY_LEN;

    for (int i = 0; i < m; i++) {
        cin >> s[i];
        if (STRING_BY_LEN.count(s[i].length()) == 0) {
            vector<string> V;
            V.push_back(s[i]);
            STRING_BY_LEN.insert({s[i].length(), V});
        } else {
            STRING_BY_LEN[s[i].length()].push_back(s[i]);
        }
    }

    map<int, multiset<char>> ALL_CAN_PLACE_CHARS;

    // 確認n個脊柱都能放甚麼字元
    for (int i = 0; i < n; i++) {
        multiset<char> ALLOWED_CHARS;
        for (auto STRING_ALLOWED : STRING_BY_LEN[a[i]]) {
            // 取出這些字串的第Bi個字元
            ALLOWED_CHARS.insert(STRING_ALLOWED[b[i] - 1]);
        }
        ALL_CAN_PLACE_CHARS.insert({i, ALLOWED_CHARS});
    }

    // 針對每個字串做檢查
    for (auto target : s) {
        // 跑過s的每個char
        bool ok = true;
        if (target.length() == n) {
            for (int i = 0; i < target.length(); i++) {
                if (ALL_CAN_PLACE_CHARS[i].count(target[i]) == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

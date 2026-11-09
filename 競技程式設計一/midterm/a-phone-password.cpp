#include <bits/stdc++.h>
#include <string>

using namespace std;

bool contains(string x, char y) {
    for (auto c : x) {
        if (c == y)
            return true;
    }
    return false;
}

bool valid_for_2(string x, int n) {
    for (int i = n + 1; i <= 9; i++) {
        if (contains(x, to_string(i)[0])) {
            return false;
        }
    }
    return true;
}

signed main() {
    int n, type;
    cin >> n >> type;
    queue<string> Q;
    Q.push("");
    vector<string> res;

    while (not Q.empty()) {
        string cur = Q.front();
        Q.pop();
        if (cur != "")
            res.push_back(cur);
        for (int i = 1; i <= n; i++) {
            auto choice = to_string(i)[0];
            if (not contains(cur, choice) and cur.size() <= n - 1) {
                if (cur.size() >= 1 and type == 1) {
                    char last_digit = cur[cur.size() - 1];
                    if (choice - last_digit >= 1) {
                        Q.push(cur + choice);
                    }
                } else {
                    Q.push(cur + choice);
                }
            }
        }
    }

    sort(res.begin(), res.end());

    if (type == 1) {
        for (auto val : res) {
            cout << val << '\n';
        }
    } else {
        for (auto val : res) {
            if (valid_for_2(val, n)) {
                cout << val << '\n';
            }
        }
    }

    return 0;
}

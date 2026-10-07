#include <bits/stdc++.h>
using namespace std;

string ans = "";
bool found = false;
bool check() {
    queue<char> Q;
    bool res = true;
    Q.push(ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        char c = ans[i];
        if (Q.size() == 0) {
            res = false;
            break;
        }

        char c_front = Q.front();

        if (c_front == c) {
            Q.pop();
        } else {
            Q.push(c);
        }
    }
    cout << ans << " is " << res << endl;
    return res;
}

void dfs(int i, int N, int L) {
    if (found)
        return;
    if (i == N) {
        cout <<"ANS:"<< ans << '\n';
        found = true;
        return;
    }

    for (int j = 0; j < L; j++) {
        char x = 'A' + j;

        ans.push_back(x);
        if (check()) {
            i++;
            dfs(i, N, L);
        }
        ans.pop_back();
    }
}

signed main() {
    int N, L;
    while (cin >> N >> L) {
        if (N == 0 and L == 0)
            break;
        found = false;
        dfs(0, N, L);
        cout << ans << '\n';
    }
}

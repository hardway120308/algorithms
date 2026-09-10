#include <bits/stdc++.h>

using namespace std;

int N;
set<string> answers;

char change(char c) { return c == '1' ? '0' : '1'; }

// backtrack
void gen(string ans) {
    if (answers.size() == pow(2, N))
        return;
    for (int i = 0; i < N; i++) {
        ans[i] = change(ans[i]);
        if (answers.count(ans) == 0) {
            answers.insert(ans);
            cout << ans << '\n';
            gen(ans);
        }
        ans[i] = change(ans[i]);
    }
}

signed main() {
    string ans;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ans.push_back('0');
    }
    answers.insert(ans);
    cout << ans << '\n';
    gen(ans);
    return 0;
}

// There is another version of Gray Code
// 可以使用位元運算：G(i) = i xor (i >> 1)
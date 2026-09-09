#include <bits/stdc++.h>

using namespace std;

vector<string> answers;

void backtrack(string ans, string choices, vector<bool> selected) {
    if (ans.length() == choices.length()) {
        answers.push_back(ans);
    }
    char previous_c;
    for (int i = 0; i < choices.length(); i++) {
        if (not selected[i] and previous_c != choices[i]) {
            selected[i] = true;
            ans.push_back(choices[i]);
            backtrack(ans, choices, selected);
            ans.pop_back();
            selected[i] = false;
            previous_c = choices[i];
        }
    }
}

signed main() {

    string S;
    cin >> S;
    vector<bool> selected(S.length(), false);
    sort(S.begin(), S.end());
    backtrack("", S, selected);

    cout << answers.size() << '\n';
    for (auto ans : answers) {
        cout << ans << '\n';
    }
}
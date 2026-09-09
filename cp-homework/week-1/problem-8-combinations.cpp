#include "bits/stdc++.h"
using namespace std;

void dfs(int start, int m, vector<int> state, vector<int> numbers) {
    if (state.size() == m) {
        for (int k = 0; k < state.size(); k++) {
            cout << state[k] << " \n"[k == state.size() - 1];
        }
        return;
    }

    // combinaation: c25取5
    for (int i = start; i < numbers.size(); i++) {
        state.push_back(numbers[i]);
        dfs(i + 1, m, state, numbers);
        state.pop_back();
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> numbers;
    vector<int> state;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    dfs(0, m, state, numbers);

    return 0;
}
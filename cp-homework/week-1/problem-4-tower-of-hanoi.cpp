#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ans;

void move(int n, int source, int tmp, int target) {
    // 先把n-1個盤子移動到tmp
    if (n == 1) {
        ans.push_back({source, target});
        return;
    }

    move(n - 1, source, target, tmp);

    ans.push_back({source, target});

    move(n - 1, tmp, source, target);
    return;
}

signed main() {
    int N;
    cin >> N;

    move(N, 1, 2, 3);

    cout << ans.size() << '\n';

    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    multiset<long long> trees;

    while (Q--) {
        int t;
        long long h;
        cin >> t >> h;

        if (t == 1) {
            // 插入一棵樹
            trees.insert(h);
        } else {
            // 刪除所有 <= h 的樹
            auto it = trees.upper_bound(h);
            trees.erase(trees.begin(), it);
        }

        cout << trees.size() << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x) { return x & -x; }

// 單點修改值，區間查詢和
struct BIT {
    vector<int> tree;
    int n;

    BIT(int num) {
        n = num;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += lowbit(idx)) {
            tree[idx] += val;
        }
    }

    // 查詢 [1, x]區間和
    int query(int x) {
        int sum = 0;

        for (; x > 0; x -= x & -x) {
            sum += tree[x];
        }

        return sum;
    }

    // 查詢 [l, r]區間和
    int query(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
    int n;

    cin >> n;
    vector<long long> h(n + 1, 0);
    vector<long long> e(n + 1, 0);
    map<int, bool> table;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> e[i];

    // 1. i能看到多少人
    vector<int> ans1(n + 1, 0);
    vector<int> st; // 高度從棧頂到棧底遞減

    for (int i = n; i >= 1; --i) {
        if (!st.empty() && e[i] > 0) {
            int max_reach = i + e[i];
            // st中的高度從棧頂到棧底遞減，所以對於第j個在棧中的牛來，都不會有在棧底和j之間的牛來高度比他高
            // 而且不需要考慮破壞遞增的元素（看不到）
            // stk: 頂 7 6 5 4 底
            // 高度：頂 8 6 5 4 底
            // 使用lower_bound找第一個 <= max_reach 的位置（因爲棧遞減）
            auto it = lower_bound(st.begin(), st.end(), max_reach, [](int idx, long long val) { return idx > val; });
            ans1[i] = distance(it, st.end());
        }

        // 維護單調遞減
        while (!st.empty() && h[st.back()] <= h[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }

    // 2. 有多少人能看到j
    // 先求每個j左邊第一個h[L] >= h[j]的位置L
    vector<int> L(n + 1, 0);
    // 維護遞減棧
    st.clear();
    for (int j = 1; j <= n; j++) {
        while (!st.empty() && h[st.back()] < h[j]) {
            // 因爲這些小於h[j]的元素不會是後面元素的答案，所以可以刪除
            st.pop_back();
        }
        // 現在棧底的高度大於L[j]，是第一個大於高度大於j的左方元素
        L[j] = st.empty() ? 0 : st.back();
        st.push_back(j);
    }
    vector<int> ans2(n + 1, 0);

    // expire[i]：在第i個人時失效的人
    vector<vector<int>> expire(n + 2);
    for (int j = 1; j <= n; j++) {
        // j會在第t個人失效（最大範圍的下一個）
        int t = j + e[j] + 1;

        if (t <= n) {
            expire[t].push_back(j);
        }
    }

    // 動態儲存expired
    BIT bit(n);
    for (int i = 2; i <= n; i++) {
        // 加入本輪新失效者
        for (int j : expire[i]) {
            bit.update(j, 1);
        }

        // 因爲L[i] = 0如果沒有左方更大者
        int l = max(1LL, L[i]);
        int r = i - 1;

        // 原本可見的牛來 - 已失效的牛來
        ans2[i] = (r - l + 1) - bit.query(l, r);
    }

    // 輸出結果
    for (int i = 1; i <= n; ++i) {
        cout << ans1[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << ans2[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

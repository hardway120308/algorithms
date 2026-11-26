#include <bits/stdc++.h>
using namespace std;

// DSU
struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        // 路徑壓縮
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Union by size
        if (sz[a] < sz[b])
            swap(a, b);

        p[b] = a;
        sz[a] += sz[b];
    }
};

// 節點connected的節點數和屬於哪個component有關係（非聯通圖）
// 同屬於一個component的節點connected的節點數會相同
signed main() {
    int N, K, L;
    cin >> N >> K >> L;

    DSU p1(N);
    DSU p2(N);

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        p1.unite(a, b);
    }
    for (int i = 0; i < L; i++) {
        int a, b;
        cin >> a >> b;
        p2.unite(a, b);
    }

    map<pair<int, int>, int> ans;

    for (int i = 1; i <= N; i++) {
        // DSU的find一樣代表兩個節點在一張圖中聯通
        // 因爲有路徑壓縮，所以如果兩個節點的(root1, root2)都相同，則它們互相聯通，並且共享同一個connected數
        // 此時這個節點屬於這個(root1, root2)，同樣屬於這個(root1, root2)的節點會共享connected數
        int root1 = p1.find(i);
        int root2 = p2.find(i);
        ans[{root1, root2}]++;
    }

    for (int i = 1; i <= N; i++) {
        int root1 = p1.find(i);
        int root2 = p2.find(i);
        cout << ans[{root1, root2}] << ' ';
    }
    cout << '\n';
}

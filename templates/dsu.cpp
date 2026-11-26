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

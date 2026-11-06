#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000000;

// 加上DSU儲存owner確保不會超時
// DSU的root是queue編號
int parent[MAXN];

/// 回傳x所在的root編號，即queue id
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

/// 把a的root改成b，即所有a queue的元素現在root是b
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    parent[a] = b;
}

signed main() {
    // io optimization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<list<int>> Q(N + 1);
    //  iterator 在移動到別的 list 之後還是會更新，永遠指向原本的元素
    vector<list<int>::iterator> pos(N + 1);

    for (int i = 1; i <= N; i++) {
        Q[i].push_back(i);
        pos[i] = Q[i].begin();
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) {
            // 在 b 的後面插入 a
            int sourceQueue = find(a);
            int targetQueue = find(b);
            auto elementA = pos[a];
            auto insertPosition = next(pos[b]);

            Q[targetQueue].splice(insertPosition, Q[sourceQueue], elementA);
            unite(a, b);
        } else {
            // 把queue A的所有元素的root改成queue b
            unite(*Q[b].begin(), *Q[a].end());
            // 把 queue a 的所有元素移動到 queue b最後
            Q[b].splice(Q[b].end(), Q[a]);
        }
    }
    // print 1 to N queue
    for (int i = 1; i <= N; i++) {
        cout << "#" << i << ": ";
        for (int x : Q[i]) {
            cout << x << ' ';
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

// splice: 移動 list 的元素到另一個 list 的指定位置(iterator)之後
// splice(target_position, source_list, source_element_to_move)
// splice(target_position, source_list)
signed main() {
    int N, M;
    cin >> N >> M;
    vector<list<int>> Q(N + 1);
    //  iterator 在移動到別的 list 之後還是會更新，永遠指向原本的元素
    vector<list<int>::iterator> pos(N + 1);
    vector<int> owner(N + 1);

    for (int i = 1; i <= N; i++) {
        Q[i].push_back(i);
        pos[i] = Q[i].begin();
        owner[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) {
            // 在 b 的後面插入 a
            int sourceQueue = owner[a];
            int targetQueue = owner[b];
            auto elementA = pos[a];
            auto insertPosition = next(pos[b]);

            Q[targetQueue].splice(insertPosition, Q[sourceQueue], elementA);
            owner[a] = targetQueue;
        } else {
            // 把 queue a 的所有元素移動到 queue b最後
            for (int x : Q[a]) {
                owner[x] = b;
            }
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
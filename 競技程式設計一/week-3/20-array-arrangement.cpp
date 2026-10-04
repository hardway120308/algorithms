#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    // 數列
    list<int> seq;

    // 存放指向seq的每一個元素的Iterator
    vector<list<int>::iterator> pos(N + 1);

    // 建立初始陣列
    for (int i = 1; i <= N; ++i) {
        seq.push_back(i);
        pos[i] = prev(seq.end()); // 儲存iterator
    }

    // list.splice 移動
    for (int q = 0; q < Q; ++q) {
        char type;
        int val;
        cin >> type >> val;

        auto it = pos[val];

        if (type == 'H') {
            // splice將list裡面的元素移動到Head
            seq.splice(seq.begin(), seq, it);
        } else {
            // splice將list裡面的元素移動到Head
            seq.splice(seq.end(), seq, it);
        }
    }

    for (int val : seq) {
        cout << val << ' ';
    }
    cout << "\n";
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
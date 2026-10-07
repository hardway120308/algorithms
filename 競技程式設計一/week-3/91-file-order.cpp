#include <bits/stdc++.h>
using namespace std;

int T = 0;

bool comp(const vector<int>& a, const vector<int>& b) { return a[T] < b[T]; }
bool comp2(const vector<int>& a, const vector<int>& b) { return a[T] > b[T]; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> files;
    vector<int> occur(4, 0);
    vector<pair<int, bool>> operations;
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        files.push_back({a, b, c, d});
    }

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        x--;
        occur[x]++;
        // 方向，如果連續點擊一個欄位多次，則會在asec 和 desc 之間切換，否則則直接設定為asec
        if (i >= 1 and operations[i - 1].first == x) {
            operations.push_back({x, not operations[i - 1].second});
        } else {
            operations.push_back({x, true});
        }
    }

    vector<pair<int, bool>> true_operations;
    vector<bool> used(4, false);

    // 從後往前找真正需要的操作，即4個欄位都找過一次
    for (int i = K - 1; i >= 0; i--) {
        auto [field, is_asec] = operations[i];
        if (!used[field]) {
            used[field] = true;
            true_operations.push_back({field, is_asec});
        }
    }

    reverse(true_operations.begin(), true_operations.end());
    for (auto [f, a] : true_operations) {
        T = f;
        if (a) {
            stable_sort(files.begin(), files.end(), comp);

        } else {
            stable_sort(files.begin(), files.end(), comp2);
        }
    }

    for (auto v : files) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

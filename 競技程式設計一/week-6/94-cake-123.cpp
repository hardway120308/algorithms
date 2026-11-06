#include <bits/stdc++.h>
#include <functional>
#include <queue>
#define int long long
#define pic pair<int, char>
#define tiiii tuple<int, int, int, int>
using namespace std;
int x, y, z, K;

signed main() {
    cin >> x >> y >> z >> K;
    vector<int> a, b, c;
    for (int i = 0; i < x; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < y; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < z; i++) {
        int x;
        cin >> x;
        c.push_back(x);
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    // 記錄是否訪問輸出過這個狀態，有則不放入PQ
    set<tuple<int, int, int>> visited;

    // 使用PQ每次取出最大的和
    // 由於三個陣列都已排序，從任何狀態往鄰居移動都只會讓和變小（單調性）；而且一定答案一定在相鄰的狀態中（前進兩個一定比前進一個小）
    // 因此 priority queue 維護的擴展的狀態中的最大值，就是global尚未輸出的最大值。
    priority_queue<tiiii> PQ;

    PQ.push({a[0] + b[0] + c[0], 0, 0, 0});
    for (int cnt = 0; cnt < K; cnt++) {
        auto [sum, i, j, k] = PQ.top();
        PQ.pop();
        cout << sum << '\n';

        if (i + 1 < a.size() and not visited.count({i + 1, j, k})) {
            visited.insert({i + 1, j, k});
            PQ.push({a[i + 1] + b[j] + c[k], i + 1, j, k});
        }
        if (j + 1 < b.size() and not visited.count({i, j + 1, k})) {
            visited.insert({i, j + 1, k});
            PQ.push({a[i] + b[j + 1] + c[k], i, j + 1, k});
        }
        if (k + 1 < c.size() and not visited.count({i, j, k + 1})) {
            visited.insert({i, j, k + 1});
            PQ.push({a[i] + b[j] + c[k + 1], i, j, k + 1});
        }
    }

    return 0;
}

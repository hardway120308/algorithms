#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.second > p2.second; }

int main() {
    int n, s;
    long long int q;
    // (望遠鏡編號,位置)
    vector<pair<int, int>> points;
    cin >> n >> s >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        points.push_back({i, x});
    }
    sort(points.begin(), points.end(), cmp);
    // 預處理，計算對於給定的X望遠鏡，要移動到哪個點
    int next[n];
    for (int i = 0; i < n; i++) {
        //
        int telescope_id = points[i].first;
        long long int lhs = 1e12;
        long long int rhs = 1e12;
        if (i - 1 >= 0) {
            lhs = abs(points[i - 1].second - points[i].second);
        }
        if (i + 1 <= n - 1) {
            rhs = abs(points[i + 1].second - points[i].second);
        }
        if (lhs < rhs) {
            next[telescope_id] = points[i - 1].first;
        } else if (lhs == rhs) {
            next[telescope_id] = min(points[i - 1].first, points[i + 1].first);
        } else {
            next[telescope_id] = points[i + 1].first;
        }
    }
    // 嘗試從S-1開始訪問
    // visited儲存訪問第n個望遠鏡時的步數,path儲存訪問第n次的望遠鏡編號
    int visited[n];
    vector<int> path;
    int steps = 0;
    int current_node = s - 1;
    for (int i = 0; i < n; i++) {
        visited[i] = -1;
    }
    while (true) {
        if (steps == q) {
            cout << current_node + 1 << endl;
            break;
        }
        if (visited[current_node] != -1) {
            long long int loop_before_start_length = visited[current_node];
            long long int loop_module = steps - loop_before_start_length;
            long long int valid_q = (q - loop_before_start_length) % loop_module;
            cout << path[loop_before_start_length + valid_q] + 1 << endl;
            break;
        }
        visited[current_node] = steps;
        path.push_back(current_node);
        current_node = next[current_node];
        steps++;
    }
}

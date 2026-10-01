#include <bits/stdc++.h>
#define int long long
using namespace std;

bool CompareData(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
    auto [a1, a2, a3, a4] = a;
    auto [b1, b2, b3, b4] = b;
    if (a1 < b1)
        return false;
    if (a1 > b1)
        return true;

    // a=b for primary condition, go to secondary
    if (a2 < b2)
        return false;
    if (a2 > b2)
        return true;

    // ...
    if (a3 < b3)
        return false;
    if (a3 > b3)
        return true;

    if (a4 < b4)
        return true;
    if (a4 > b4)
        return false;

    return false;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        // milk 總數,最多的個人持有milk數,人數,索引
        vector<tuple<int, int, int, int>> groups;
        vector<vector<int>> peoples(N);
        for (int i = 0; i < N; i++) {
            int K;
            int sum = 0;
            cin >> K;
            vector<int> members;
            for (int j = 0; j < K; j++) {
                int x;
                cin >> x;
                sum += x;
                members.push_back(x);
            }

            int max_milk = *max_element(members.begin(), members.end());
            groups.push_back({sum, max_milk, members.size(), i});
            peoples[i] = members;
        }

        sort(groups.begin(), groups.end(), CompareData);

        for (auto [a, b, c, d] : groups) {
            for (auto p : peoples[d]) {
                cout << p << ' ';
            }
            cout << '\n';
        }
    }
}
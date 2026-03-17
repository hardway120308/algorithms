#include <bits/stdc++.h>

#define int long long

using namespace std;

bool mycmp(pair<int, int> a, pair<int, int> b) {
    // 首先依照first降序，再以second升序
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        a.push_back({score, i + 1});
    }
    sort(a.begin(), a.end(), mycmp);
    if (a[0].second == 1) {
        cout << "-1" << endl;
    } else {
        cout << a[0].second << endl;
    }
    return 0;
}

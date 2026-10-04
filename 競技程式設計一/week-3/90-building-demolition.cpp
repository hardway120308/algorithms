#include <bits/stdc++.h>
#define int long long
using namespace std;

// 比較單位罰款，單位罰款 = 罰款 / 天數，越大越優先
// 交叉相乘比較，避免浮點數誤差
// 單位成本較高的需要先做
bool mycomp(pair<int, int> a, pair<int, int> b) { return a.first * b.second > b.first * a.second; }

signed main() {
    int N;
    cin >> N;
    vector<pair<int, int>> L(N);
    int nowfine = 0;

    for (int i = 0; i < N; i++) {
        cin >> L[i].first >> L[i].second;
        nowfine += L[i].first;
    }

    sort(L.begin(), L.end(), mycomp);

    int ans = 0;

    for (auto c : L) {
        ans += nowfine * c.second;
        nowfine -= c.first;
    }

    cout << ans << endl;
}
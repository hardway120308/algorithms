#include <bits/stdc++.h>
#define int long long
using namespace std;

// 檢查days之後能力是否可以贏得至少k場比賽
bool check(vector<pair<int, int>>& horses, vector<int>& C, int days, int k) {
    int win = 0;
    int opponentIndex = 0;
    // 計算days之後的能力值
    vector<int> newAbilities;
    for (int i = 0; i < horses.size(); i++) {
        int newAbility = horses[i].first + horses[i].second * days;
        newAbilities.push_back(newAbility);
    }
    sort(newAbilities.begin(), newAbilities.end());
    for (auto ability : newAbilities) {
        if (opponentIndex < C.size() && ability > C[opponentIndex]) {
            win++;
            opponentIndex++;
        } else {
            // 如果不能贏，則跳過這個馬匹
            continue;
        }
    }
    return win >= k;
}

// 二分搜尋找出最少需要的天數
int binarySearch(vector<pair<int, int>>& horses, vector<int>& C, int K, int L, int R) {
    while (L < R) {
        int mid = L + (R - L) / 2;
        if (check(horses, C, mid, K)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    return L;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int give_up = N - K;
        vector<pair<int, int>> horses(N);
        vector<int> C(N);
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            horses[i] = {a, b};
        }
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }
        sort(C.begin(), C.end());

        for (int i = 0; i < give_up; i++) {
            C.pop_back();
        }

        // 針對每一個馬匹，計算最多需要k天的訓練（能力增加為a+kb）才能超過第一個大於等於自己現在能力的馬匹，並且計算出需要的最少天數
        // 可以放棄N-K場
        int M = 0;
        // 二分搜尋檢查能否在S天內贏得K場
        int result = binarySearch(horses, C, K, 0, 1e9);
        if (result >= 1e9) {
            cout << -1 << endl;
        } else {
            cout << result << endl;
        }
    }
}

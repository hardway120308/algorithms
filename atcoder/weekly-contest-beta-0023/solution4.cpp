#include <bits/stdc++.h>
#include <utility>

using namespace std;

int main() {
    const int NEG_INF = -1;
    int n, s, t;
    cin >> n >> s >> t;

    int ans = -1;
    // dp表代表選擇了k個項目，總重量**精確**為w的最大利潤
    int dp[n + 1][s + 1];
    vector<pair<int, int>> items;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = NEG_INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        int profit = p - c;
        if (profit > 0 and w <= s) {
            items.push_back(make_pair(w, profit));
        }
    }

    for (auto item : items) {
        int weight = item.first;
        int val = item.second;
        // 倒序避免重複選取
        for (int i = n; i >= 1; i--) {
            // 要運送此請求至少要w的重量，但最多不會超過S
            for (int curr_weight = weight; curr_weight <= s; curr_weight++) {
                // 如果可以透過選擇項目到達
                if (dp[i - 1][curr_weight - weight] != NEG_INF) {
                    // dp表更新為前一個項目中選取本項目或者保留目前的值不變
                    // 要取和現在值max的原因是如果有同重量的物品，則第i=0迴圈進來之後會壓到同樣dp[1][W_1]的值
                    // 此時需要判斷誰的利潤更大才是局部最優解
                    dp[i][curr_weight] = max(dp[i][curr_weight], dp[i - 1][curr_weight - weight] + val);
                }
            }
        }
    }

    for (int k = 0; k <= n; k++) {
        for (int w = 0; w <= s; w++) {
            if (dp[k][w] >= t) {
                cout << k << endl;
                return 0;
            } else if (k == n and w == s) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#define int long long

using namespace std;

// 對於每個Ai，可以化成
// Ai = Ai + n * k(n>=0且n belong to N)
// 所以Ai可以是任意和他mod K餘數一樣的數（除法原理）
// 令Bi = Ai mod K，對B排序
// 初始的ans = B_n - B_1
// 遍歷B，對任意一個B_i+K(還有它前面的B_i-1,...)使其成爲最大值
// 則B_i+1是最小值
// 逐一檢查當前ans是否比ans更小即可
// 循環區間覆蓋問題
signed main() {
    int n, k;
    cin >> n >> k;

    int b[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // Reduce to base values within [0, K)
        b[i] = x % k;
    }

    sort(b, b + n);

    // 一開始的答案
    int ans = b[n - 1] - b[0];

    for (int i = 0; i < n - 1; i++) {
        long long now_ans = (b[i] + k) - b[i + 1];
        if (now_ans < ans) {
            ans = now_ans;
        }
    }

    cout << ans << endl;

    return 0;
}

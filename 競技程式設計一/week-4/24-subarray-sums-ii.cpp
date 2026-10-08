#include <bits/stdc++.h>
#define int long long
using namespace std;

// 1-based
signed main() {
    int n, x;
    int ans = 0;
    cin >> n >> x;
    // 因為有負數，所以前綴和可能會有多次出現
    // 需要保存特定前綴和的出現次數
    // 前綴和, 發生次數
    map<int, int> prefix_sum_occur;
    int current_prefix_sum = 0;
    prefix_sum_occur[0] = 1;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        current_prefix_sum += val;
        // x = Sij = Pj - P(i-1)
        // P(i-1) = Pj - x
        int target = current_prefix_sum - x;
        if (prefix_sum_occur.count(target)) {
            ans += prefix_sum_occur[target];
        }

        prefix_sum_occur[current_prefix_sum]++;
    }

    cout << ans << '\n';
}

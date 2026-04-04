#include <bits/stdc++.h>

using namespace std;

signed main() {
    string S, T;
    cin >> S >> T;

    int dp[S.length() + 1];
    dp[0] = 0;
    for (int i = 1; i < S.length() + 1; i++) {
        int sum = 0;
        // 考慮以i個字串為結尾的substring中。有多少個substring不含T作為subsequence
        // 窮舉起始在0,起始在1...起始到i-1
        for (int j = 0; j < i; j++) {
            bool contains_sub_seq = true;
            // Substring 起始index:j 結束:i-1，左閉右閉
            int NOW_IDX = j;
            for (int k = 0; k < T.length(); k++) {
                while (S[NOW_IDX] != T[k] and NOW_IDX < i) {
                    NOW_IDX++;
                }
                if (NOW_IDX < i and S[NOW_IDX] == T[k]) {
                    continue;
                } else {
                    contains_sub_seq = false;
                    break;
                }
            }
            if (not contains_sub_seq) {
                // 剩下所有都不能有sub seq
                sum += (i - j);
                break;
            } else {
                continue;
            }
        }
        dp[i] = dp[i - 1] + sum;
    }
    cout << dp[S.length()] << endl;
}

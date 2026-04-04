#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S, T;
    if (!(cin >> S >> T))
        return 0;

    int n = S.length();
    int m = T.length();

    // nxt[i][c] 儲存字元 'c' 在索引 'i'（含）之後第一次出現的位置
    // 初始化為 'n'，表示找不到該字元
    vector<vector<int>> nxt(n + 1, vector<int>(26, n));

    for (int i = n - 1; i >= 0; --i) {
        for (int c = 0; c < 26; ++c) {
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][S[i] - 'a'] = i;
    }

    long long ans = 0;

    // 測試每一個起始位置 'i'
    for (int i = 0; i < n; ++i) {
        int curr = i;
        bool matched = true;

        // 貪婪地尋找字串 T 作為子序列
        // 窮舉T的所有char
        for (int j = 0; j < m; ++j) {
            // 找到在索引curr之後第一次出現T的這個Char的位置
            // 如果此位置小於n(在S結束之前)，則繼續
            // 然後從這個位置的下一個開始找下一個T的char
            curr = nxt[curr][T[j] - 'a'];
            if (curr == n) { // 在結束之前找不到
                matched = false;
                break;
            }
            curr++; // 移動到下一個字元(curr原本指向當前T的Char)
        }

        if (matched) {
            // curr - 1 是 T 最終匹配的字元索引。
            // 所有在 (curr - 1) 之前結束的substring都無法形成 T。
            // 他們都是答案
            ans += (curr - 1) - i;
        } else {
            // 從 'i' 開始根本無法形成 T，所有從i開始的substring都是合法的。
            ans += n - i;
        }
    }

    cout << ans << "\n";
    return 0;
}

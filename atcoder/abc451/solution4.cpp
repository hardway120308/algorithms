#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int N;
    cin >> N;

    // 初始數：預先依照他們的長度排序
    vector<string> P_by_len[10];
    for (int i = 0; i < 30; ++i) {
        string p = to_string((int)pow(2, i));
        if (p.length() < 10) {
            P_by_len[p.length()].push_back(p);
        }
    }

    // dp[i] will store valid concatenated strings of exactly length i
    vector<string> dp[10];
    dp[0].push_back("");

    // Build strings from length 0 up to 9
    for (int i = 0; i < 10; i++) {
        // 去重
        sort(dp[i].begin(), dp[i].end());
        dp[i].erase(unique(dp[i].begin(), dp[i].end()), dp[i].end());

        for (const string& s : dp[i]) {
            // 給每個2的字串加到末端
            for (int l = 1; l < 10 - i; l++) {
                for (const string& p : P_by_len[l]) {
                    dp[i + l].push_back(s + p);
                }
            }
        }
    }

    vector<int> good_ints;

    for (int i = 1; i < 10; ++i) {
        for (const string& s : dp[i]) {
            good_ints.push_back(stoi(s));
        }
    }

    cout << good_ints[N - 1] << endl;

    return 0;
}

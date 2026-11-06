#include <bits/stdc++.h>
#define int long long
using namespace std;

// sliding window
signed main() {
    int N;
    int limits[26];
    cin >> N;
    for (int i = 0; i < 26; i++) {
        cin >> limits[i];
    }

    string S;
    cin >> S;

    // 因爲要求剛好3個distinct char，所以只有兩種情況
    // Case 1. 取到三個char的出現次數全部都小於limits，則star count爲所有出現次數中最高者
    // Case 2. 只有一個char的出現次數超過limits，則star count爲這個超過的char的出現次數
    // 依據這兩者進化sliding window 維護left到right 整個序列都是beautiful string
    int left = 0;
    int frequencys[26];
    int distinct = 0;
    int ans = 0;
    int bad = 0; // number of char whose occurence greater than its limit
    memset(frequencys, 0, sizeof(frequencys));
    // case1: 三個char都不超過各自limit
    for (int right = 0; right < N; right++) {
        int idx = S[right] - 'a';
        if (frequencys[idx] == 0)
            distinct++;
        frequencys[idx]++;

        if (frequencys[idx] == limits[idx] + 1)
            bad++;

        // 如果有超過三個distinct或者有bad(不屬於這個case的)，就推進left減少到只有3個distinct同時沒有bad
        while (distinct > 3 or bad > 0) {
            int left_idx = S[left] - 'a';
            if (frequencys[left_idx] == limits[left_idx] + 1)
                --bad;
            frequencys[left_idx]--;
            if (frequencys[left_idx] == 0)
                distinct--;
            left++;
        }

        // 三個相異char且都不超過limit，更新ans
        if (distinct == 3) {
            int mx = 0;
            for (int i = 0; i < 26; ++i) {
                mx = max(mx, frequencys[i]);
            }
            ans = max(ans, mx);
        }
    }

    // Case2: 只有y 這個char超過限制
    for (int y = 0; y < 26; ++y) {
        memset(frequencys, 0, sizeof(frequencys));

        left = 0;
        distinct = 0; // 相異的非y字母數量
        bad = 0;      // 非y的字母超過限制的數量

        for (int right = 0; right < N; ++right) {
            int idx = S[right] - 'a';
            frequencys[idx]++;

            if (idx != y) {
                if (frequencys[idx] == 1)
                    distinct++;
                if (frequencys[idx] == limits[idx] + 1)
                    bad++;
            }

            // 如果大於兩個distinct或者有除了y以外超過limit就推進left
            while (distinct > 2 || bad > 0) {
                int left_idx = S[left] - 'a';

                // 首先這個char不能是y，y不能被移除
                if (left_idx != y) {
                    if (frequencys[left_idx] == limits[left_idx] + 1)
                        bad--;
                    frequencys[left_idx]--;
                    if (frequencys[left_idx] == 0)
                        distinct--;
                } else {
                    frequencys[left_idx]--;
                }

                left++;
            }

            // 有兩個不是y的，而且y的頻率超過limit of y
            if (distinct == 2 && frequencys[y] > limits[y]) {
                ans = max(ans, frequencys[y]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

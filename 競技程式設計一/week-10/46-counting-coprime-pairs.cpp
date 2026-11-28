#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> factorization(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res.emplace_back(i);
        }
    }
    if (n != 1)
        res.emplace_back(n);
    return res;
}

void inclusion_exclusion_principle(vector<int> prime_factor, function<void(int, int)> callback) {}
signed main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int Max_a = 0;

    for (int& x : a) {
        cin >> x;
        Max_a = max(Max_a, x);
    }
    // cnt[d]: 已經處理過的數字中，有多少個能被 d 整除（是d的倍數）
    vector<int> cnt(Max_a + 1, 0);

    int ans = 0;
    // 處理過的數字數量
    int processed = 0;

    for (int x : a) {
        // 取得質因數
        vector<int> primes = factorization(x);

        // 之間處理過，且和目前的x不互質的數字數量
        int bad = 0;

        // 舉例：primes是2,3,5，
        // 則對於{2},{3},{5}等子集合，flag都是1，bad會加上cnt[d]
        // 對於{2,3},{3,5},{2,5}等子集合，因爲有二個元素，所以flag會是-1*-1*-1=-1
        // ...
        for (int mask = 1; mask < (1 << primes.size()); mask++) {
            int d = 1;
            int flag = -1;

            // 排容原理
            // 次數出現1次的+
            // 次數出現2次的時候-
            // 出現3次時候+
            // +-+-+-+-...
            for (int j = 0; j < primes.size(); j++) {
                if (mask & (1 << j)) {
                    d *= primes[j];
                    flag *= -1;
                }
            }

            bad += flag * cnt[d];
        }

        // 與 x 互質的已處理數量
        // 每次增加(a,x)這個互質數對，a是已經處理過的，x是現在處理的
        // 每一個互質數對只會在較晚被處理的數字出現時計算一次
        ans += processed - bad;

        // 更新 cnt：cnt[x的所有質因數子集合乘積]+=1
        for (int mask = 1; mask < (1 << primes.size()); mask++) {
            int d = 1;

            for (int j = 0; j < primes.size(); j++) {
                if (mask & (1 << j))
                    d *= primes[j];
            }

            cnt[d]++;
        }

        processed++;
    }

    cout << ans << '\n';
}

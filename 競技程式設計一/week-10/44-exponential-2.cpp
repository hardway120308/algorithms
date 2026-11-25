#include <bits/stdc++.h>
#define int long long
using namespace std;

int fastPow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        // b是奇數
        if (b & 1)
            // 乘上一個數再取模等於乘上此數取模之後的值
            res = res * (a % mod);
        // 次方右移1（b=b/2）（已經處理b是奇數的狀況）
        b >>= 1;
        // a^b = a^(b/2*2) = (a^2)^(b/2)
        a = a * a % mod;
    }
    return res;
}

// calc a^(b^c) % 1e9
signed main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        const int MOD = 1e9 + 7;

        cin >> a >> b >> c;
        //
        // By 費馬小定理，a^(p-1) ≡ 1 (mod p)，所以a^n(p-1) = 1 (mod p)（乘上一個數再取模等於乘上此數取模後的值）
        // 所以a^(n(p-1)+r) = a^r (mod p)，令k = n(p-1)+r，則k爲任意正整數
        // 則a^k = a^r (mod p) 其中r = k % (p-1)
        // 所以有k爲任意正整數，a爲整數且p爲質數，a^k = a^(k%p-1)
        // 所以 a^(b^c) ≡ a^(b^c mod (p-1)) (mod p)
        // 利用快速冪求出
        int exponent = fastPow(b, c, MOD - 1);
        cout << fastPow(a, exponent, MOD) << '\n';
    }
}

#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime;
vector<int> primes;
// 一個數的最小質因數
vector<int> LPF;

// 埃氏篩
void sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[1] = false;
    for (int k = 2; k <= n; k++) {
        if (is_prime[k]) {
            primes.emplace_back(k);
            for (int times = 2; times * k <= n; times++) {
                is_prime[times * k] = false;
            }
        }
    }
}

// 線性篩，每個合數只被自己最小的質因數篩選過一次
void sieve_2(int n) {
    is_prime.assign(n + 1, true);
    LPF.assign(n + 1, 0);
    is_prime[1] = false;
    for (int k = 2; k <= n; k++) {
        if (is_prime[k])
            primes.emplace_back(k);
        for (auto p : primes) {
            if (p * k > n)
                break;
            is_prime[p * k] = false;
            // k 已經是某個（它的最小的）質因數的倍數，所以不用繼續檢查更大的質因數
            if (k % p == 0)
                break;
        }
    }
}

// 線性篩，計算LPF版本
void sieve_3(int n) {
    LPF.assign(n + 1, 1);

    for (int k = 2; k <= n; k++) {
        // LPF[k] == 1代表是質數
        if (LPF[k] == 1) {
            primes.emplace_back(k);
            // LPF是自己
            LPF[k] = k;
        }
        for (auto p : primes) {
            if (p * k > n)
                break;
            LPF[p * k] = p;
            // k 已經是某個（它的最小的）質因數的倍數，所以不用繼續檢查更大的質因數
            if (k % p == 0)
                break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    sieve_3(n);
    for (auto x : primes) {
        cout << x << ' ';
    }
    cout << '\n';
}

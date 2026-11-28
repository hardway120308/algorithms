#include <bits/stdc++.h>

using namespace std;

pair<int, int> extgcd(int a, int b) {
    if (b == 0) {
        // gcd(a,0)=a
        return {1, 0};
    }
    auto [px, py] = extgcd(b, a % b);
    // ax+by = gcd(a,b) = gcd(b, a % b) = gcd(b, a - [a / b] b)，取下高斯
    return {py, px - a / b * py};
}

int mod_inverse(int a, int m) { return (extgcd(a, m).first + m) % m; }

auto garner(vector<int> A, vector<int> M) {
    vector<int> X(A.size());
    for (int i = 0; i < A.size(); i++) {
        X[i] = A[i];
        for (int j = 0; j < i; j++) {
            X[i] = ((X[i] - X[j]) * mod_inverse(M[j], M[i])) % M[i];
            if (X[i] < 0)
                X[i] += M[i];
        }
    }
    return X;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        // 一次同餘方程組（m_1,m_2,...互質）
        // X = a_1 (mod m_1)
        // X = a_2 (mod m_2)
        // ...
        vector<int> A;
        vector<int> M;
        for (int i = 0; i < 3; i++) {
            int a, b;
            cin >> a >> b;
            A.emplace_back(b);
            M.emplace_back(a);
        }

        auto x = garner(A, M);
        auto ans = 0;
        auto M_mul = 1;
        for (int i = 0; i < x.size(); i++) {
            ans += (x[i] * M_mul);
            M_mul *= M[i];
        }
        cout << ans << '\n';
    }
}

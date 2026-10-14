#include <bits/stdc++.h>

using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    K--;
    vector<int> S2(N);
    vector<int> S(N);
    for (int i = 0; i < N; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        S[i] = a + b + c;
        S2[i] = a + b + c;
    }
    nth_element(S.begin(), S.begin() + K, S.end(), std::greater<int>());

    for (auto i : S2) {
        if (i + 300 >= S[K]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
signed main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int mx = *max_element(A.begin(), A.end());
    // 記錄有幾個A的元素x滿足 mx | x
    vector<int> freq(mx + 1, 0);

    for (int i = 0; i < n; i++) {
        freq[A[i]]++;
    }

    for (int num = mx; num >= 1; num--) {
        // 尋找是否有num | a and num | b (a!=b)
        // 也就是說a=k*num, b = c*num
        // 檢查頻率表中A是否出現過即可
        int num_divides_X_count = freq[num];
        for (int i = 2; i * num <= mx; i++) {
            num_divides_X_count += freq[i * num];
        }
        // 有兩個數滿足 num | a and num | b
        if (num_divides_X_count >= 2) {
            cout << num << '\n';
            return 0;
        }
    }
}

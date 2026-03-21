#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int missing = 1;
    // missing表示能被組出來的最小數
    // 1,2,3,...missing-1也能被組出來
    // 所以遍歷陣列
    // a[i]+1,a[i]+2,...a[i]+missing-1也能被組出來
    // 也就是說當a[i] > missing時，missing就是不能被組出來的答案（中間有比missing大的數不能被組出來）
    // 此時輸出missing
    for (int x = 0; x < n; x++) {
        if (a[x] > missing) {
            break;
        }
        missing += a[x];
    }
    cout << missing << endl;
}

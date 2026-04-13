#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        set<int> b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b.insert(a[i]);
        }
        if (b.size() < n) {
            // 如果有重複的數字，則排序過後一定可以被組成
            cout << -1 << endl;
        } else {
            // 不可能被前面的數字組成（都比自己大）
            sort(a, a + n);
            for (int i = n - 1; i >= 0; i--) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

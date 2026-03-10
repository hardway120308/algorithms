#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (n - k + 1); i++) {
        if (a[i] == 1) {
            // 燈泡不亮，則讓他亮
            ans++;
            for (int j = i; j < i + k; j++) {
                a[j] = not a[j];
            }
        } else {
            continue;
        }
    }

    for (int i = n - k; i < n; i++) {
        if (a[i] == 1) {
            ans = -1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

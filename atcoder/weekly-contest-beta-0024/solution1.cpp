#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (s[a - 1] > s[b - 1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

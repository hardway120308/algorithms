#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = k;
    bool know_rumors[n];
    memset(know_rumors, 0, sizeof(know_rumors));
    for (int i = 0; i < k; i++) {
        know_rumors[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (know_rumors[a] xor know_rumors[b]) {
            know_rumors[a] = know_rumors[a] or true;
            know_rumors[b] = know_rumors[b] or true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

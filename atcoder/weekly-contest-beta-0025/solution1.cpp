#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    int ans = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        if (score < x) {
            ans++;
        }
    }
    cout << ans << endl;
}

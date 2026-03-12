#include <bits/stdc++.h>

using namespace std;

int wn[51];
int pn[51];
int n, s, t;
int ans = -1;

int dp(int n, int weight, int selected) {
    if (n <= 0) {
        return pn[0];
    }
    if (weight + wn[n] < s) {
        int x = min(dp(n, weight - wn[n], selected + 1), dp(n - 1, weight, selected));
        if (x >= t and selected <= ans) {
            ans = selected;
        }
        return x;
    } else {
        return dp(n, weight, selected);
    }
}

int main() {
    cin >> n >> s >> t;

    for (int i = 0; i < n; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        int profit = p - c;
        wn[i] = w;
        pn[i] = profit;
    }

    cout << dp(n - 1, 0, 0) << endl;

    cout << ans << endl;
    return 0;
}

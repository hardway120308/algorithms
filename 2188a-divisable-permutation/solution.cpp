#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans[n];
        int used[n + 1];
        for (int i = 0; i <= n; ++i) {
            used[i] = 0;
        }
        ans[n - 1] = n;
        ans[n - 2] = 1;
        for (int i = n - 3; i >= 0; --i) {
            // the abs value of differnece of the item i and item i+1 is i+1
            // so we try to select the smallest possible value that is not used
            // yet
            int first_select = ans[i + 1] + (i + 1);
            int second_select = ans[i + 1] - (i + 1);
            if (first_select > 0 and first_select < n and !used[first_select]) {
                ans[i] = first_select;
            } else {
                ans[i] = second_select;
            }
            used[ans[i]] = 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

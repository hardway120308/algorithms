#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    int department_first_month[m + 1];
    int department_next_month[m + 1];
    memset(department_first_month, 0, sizeof(department_first_month));
    memset(department_next_month, 0, sizeof(department_next_month));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        department_first_month[x]++;
        department_next_month[y]++;
    }

    for (int i = 1; i <= m; i++) {
        cout << department_next_month[i] - department_first_month[i] << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string dfs(int n, vector<int> a) {
    string S;
    if (n == 1) {
        int MAX_REPEAT_COUNT = ((a[n - 1] - 1) * 2) + 1;
        for (int j = 0; j < a[n - 1]; j++) {
            int REPEAT_COUNT = (j * 2) + 1;
            int k = 0;
            while (k < MAX_REPEAT_COUNT) {
                if (k >= ((MAX_REPEAT_COUNT - REPEAT_COUNT) / 2) and
                    k < ((MAX_REPEAT_COUNT - REPEAT_COUNT) / 2 + REPEAT_COUNT)) {
                    S.push_back('*');
                } else {
                    S.push_back(' ');
                }
                k++;
            }
            S.push_back('\n');
        }
        return S;
    }

        return S;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dfs(n, a);

    return 0;
}
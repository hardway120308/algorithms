#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        V.push_back({k, i + 1});
    }

    sort(V.begin(), V.end());

    int x1 = -1;
    int left;
    int right;
    for (int i = 0; i < n; i++) {
        if (x1 != -1)
            break;
        left = i + 1;
        right = n - 1;
        while (left < right) {
            int sum = V[i].first + V[left].first + V[right].first - x;
            //cout << V[i].first << ' ' << V[left].first << ' ' << V[right].first << endl;

            if (sum == 0) {
               // cout << "B";
                x1 = i;
                break;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    if (x1 != -1 and V[x1].first + V[left].first + V[right].first == x) {
        cout << V[x1].second << ' ' << V[left].second << ' ' << V[right].second;
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int NUM = n * 3;
        deque<int> BASED(NUM);
        iota(BASED.begin(), BASED.end(), 1);

        // 連續為3
        for (int i = 1; i <= NUM; i++) {
            if (i % 3 == 2 or i % 3 == 0) {
                int x = BASED.back();
                BASED.pop_back();
                cout << x << ' ';
            } else {
                int x = BASED.front();
                BASED.pop_front();
                cout << x << ' ';
            }
        }
        cout << endl;
    }
}

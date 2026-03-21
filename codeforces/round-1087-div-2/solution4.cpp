#include <bits/stdc++.h>
#define int long long
using namespace std;

int dfs(int r, int g, int b, string now_str, int l, set<int> novalid) {
    char x[3] = {'R', 'G', 'B'};
    for (auto choice : x) {
        if (novalid.count(choice) == 0) {
            novalid.clear();
            novalid.insert(now_str[l - 3]);
            novalid.insert(now_str[l - 1]);
            if (choice == 'R') {

            } else if (choice == 'G') {

            } else {
            }
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int r, g, b;
        int i = 3;
        cin >> r >> g >> b;
        // 陣列長度: 2n
        string valid_str = "RGB";
        while (r > 0 or b > 0 or g > 0) {
            valid_str += 'R';
            auto before_3 = valid_str[i - 3];
            auto before_1 = valid_str[i - 3];
        }
    }
}

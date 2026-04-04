#include <bits/stdc++.h>

using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0) {
                cout << '#';
            } else if (i == h - 1)
                cout << '#';
            else if (j == 0) {
                cout << '#';
            } else if (j == w - 1) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}

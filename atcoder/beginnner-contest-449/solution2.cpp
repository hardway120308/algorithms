#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    for (int i = 0; i < q; i++) {
        int type, val;
        cin >> type >> val;
        if (type == 1) {
            cout << val * w << endl;
            h -= val;
        }
        if (type == 2) {
            cout << val * h << endl;
            w -= val;
        }
    }
    return 0;
}

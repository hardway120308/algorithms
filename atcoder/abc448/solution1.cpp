#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        if (item < x) {
            x = item;
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

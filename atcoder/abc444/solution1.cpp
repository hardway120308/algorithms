#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string n;
    cin >> n;
    if (n[0] == n[1] and n[1] == n[2] and n[0] == n[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

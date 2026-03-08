#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> dn;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dn.insert(a);
    }

    cout << dn.size() << endl;

    return 0;
}

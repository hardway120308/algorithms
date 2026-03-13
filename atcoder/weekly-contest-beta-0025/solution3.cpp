#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;

    long long d[n];
    for (long long int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d, d + n, greater<long long>());

    if (m < n) {
        cout << d[m] << endl;
    } else {
        cout << 0 << endl;
    }
}

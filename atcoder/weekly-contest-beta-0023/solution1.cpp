#include <bits/stdc++.h>

using namespace std;
int main() {
    long long int n, m, r;
    cin >> n >> m >> r;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        long long int x;
        cin >> x;
        sum += x;
    }

    sum += r * m;
    cout << sum << endl;
    return 0;
}

#include "bits/stdc++.h"
using namespace std;
vector<long long> apples;
long long ans = 1e10 + 7;

signed main() {
    string n;
    getline(cin, n);

    string input;
    getline(cin, input);
    stringstream ss(input);

    int a;

    while (ss >> a) {
        apples.push_back(a);
    }

    // 窮舉子集合
    for (int bitmask = 0; bitmask < (1 << apples.size()); bitmask++) {
        long long a = 0;
        long long b = 0;
        // Example: bitmask = 0010
        // Now Item is 3: them (1<<j) = 0100
        // the result is false, so item 3 would not being added to the 集合
        for (int j = 0; j < apples.size(); j++) {
            if ((1 << j) & bitmask) {
                a += apples[j];
            } else {
                b += apples[j];
            }
        }

        ans = min(ans, abs(a - b));
    }

    cout << ans << '\n';

    return 0;
}
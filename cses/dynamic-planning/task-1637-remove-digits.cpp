#include <bits/stdc++.h>
#define vi vector<int>
#define int long long
using namespace std;

int mem[1000005];

vi getDigits(int x) {
    vi res;
    while (x >= 1) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

int dp(int x) {
    if (x < 10) {
        return 1;
    }
    if (mem[x] != 0) {
        return mem[x];
    }
    int res = 1e9;
    vi digits = getDigits(x);
    for (auto i : digits) {
        if (i != 0) {
            res = min(res, dp(x - i) + 1);
        }
    }
    mem[x] = res;
    return res;
}

signed main() {
    int n;
    cin >> n;
    memset(mem, 0, sizeof(mem));
    cout << dp(n) << endl;
}

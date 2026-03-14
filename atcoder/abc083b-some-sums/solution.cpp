#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int digit_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int n, a, b;
    vector<int> ans;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        if (a <= digit_sum(i) and digit_sum(i) <= b) {
            ans.push_back(i);
        }
    }
    // 計算容器總和
    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
    return 0;
}

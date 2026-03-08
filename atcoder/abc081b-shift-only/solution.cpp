#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int an[n];
    int factors_2[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> an[i];
        factors_2[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        while (an[i] % 2 == 0) {
            factors_2[i]++;
            an[i] /= 2;
        }
    }

    ans = *min_element(factors_2, factors_2 + n);

    cout << ans << endl;
}

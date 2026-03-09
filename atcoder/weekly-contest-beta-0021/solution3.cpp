#include <bits/stdc++.h>
#include <functional>
#define intx long long

using namespace std;

int main() {
    intx n, k;
    intx ans = 0;
    cin >> n >> k;
    intx data_of_centers[n];
    for (intx i = 0; i < n; i++) {
        intx cost, m_count;
        intx benefits = 0;
        cin >> cost >> m_count;
        for (intx j = 0; j < m_count; j++) {
            intx x;
            cin >> x;
            benefits += x;
        }
        if (benefits - cost > 0) {
            data_of_centers[i] = benefits - cost;
        } else {
            data_of_centers[i] = 0;
        }
    }

    sort(data_of_centers, data_of_centers + n, std::greater<intx>());

    for (intx i = 0; i < k; i++) {
        ans += data_of_centers[i];
    }

    cout << ans << endl;

    return 0;
}

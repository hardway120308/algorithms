#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int l[1000];
int ans = 0;

void dfs(int step, int pos, int passes) {
    // Base case: If we have made all N moves, update the maximum passes seen
    if (step == n) {
        ans = max(ans, passes);
        return;
    }

    // 選擇1 右
    long long next_pos_plus = pos + 2 * l[step];
    // 跨過
    int passes_plus = passes + ((pos > 0) != (next_pos_plus > 0) ? 1 : 0);
    dfs(step + 1, next_pos_plus, passes_plus);

    // 選擇2 左
    long long next_pos_minus = pos - 2 * l[step];
    int passes_minus = passes + ((pos > 0) != (next_pos_minus > 0) ? 1 : 0);
    dfs(step + 1, next_pos_minus, passes_minus);
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    dfs(0, 1, 0);

    cout << ans << "\n";
    return 0;
}

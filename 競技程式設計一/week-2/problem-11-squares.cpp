#include <bits/stdc++.h>
using namespace std;

int target;
int bucket[4];
vector<int> sticks;

/// @brief  遞迴每個棒子，嘗試放入4個桶中
/// @param idx 當前要放入的棒子編號
/// @return 是否可以分到4個桶子都是target
bool dfs(int idx) {
    if (idx == (int)sticks.size()) {
        // 檢查是否三個桶都裝滿
        return bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
    }

    int len = sticks[idx];
    for (int i = 0; i < 4; i++) {
        if (bucket[i] + len > target)
            continue;

        // 剪枝：因爲桶和桶之間只有已經裝入長度的區別，所以如果這個桶和上一個桶有相同容量（我們確保了它遞增）就跳過
        if (i > 0 && bucket[i] == bucket[i - 1])
            continue;

        bucket[i] += len;
        if (dfs(idx + 1))
            return true;
        bucket[i] -= len;

        // 剪枝：如果不能放入空桶，則這一根棒子不能放進去
        if (bucket[i] == 0)
            break;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        sticks.assign(M, 0);
        int sum = 0;
        for (int i = 0; i < M; i++) {
            cin >> sticks[i];
            sum += sticks[i];
        }

        if (sum % 4 != 0) {
            cout << "no\n";
            continue;
        }

        target = sum / 4;

        sort(sticks.begin(), sticks.end(), greater<int>());

        memset(bucket, 0, sizeof(bucket));
        cout << (dfs(0) ? "yes\n" : "no\n");
    }
    return 0;
}
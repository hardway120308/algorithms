
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    while (cin >> n) {
        int ans = 0;
        vector<int> sticks(n + 1, 0); // 最後一個元素為哨兵，值為 0

        for (int i = 0; i < n; i++) {
            cin >> sticks[i];
        }

        stack<int> stk;

        for (int i = 0; i <= n; i++) {
            // 如果棧頂的高度大於或等於目前棒子的高度，
            // 代表棧頂高度的矩形不能再向右延伸，可以計算面積
            // Namely, 我們找到了右邊界爲i-1，高度爲sticks[stk.top()]的矩形面積最大值
            while (!stk.empty() && sticks[stk.top()] >= sticks[i]) {

                // 被彈出的棒子高度，就是目前矩形的高度
                int height = sticks[stk.top()];

                // 彈出棧頂，新的棧頂是左側第一個高度小於
                // height 的棒子；如果棧為空，代表左側沒有較矮的棒子(可以延伸到最左邊)
                // 新棧頂+1即爲左邊界
                stk.pop();

                // i 是右側第一個高度小於或等於 height 的位置，
                // 因此矩形的右邊界是 i-1
                // 左邊界是新棧棧頂+1
                int width = stk.empty() ? i : i - 1 - stk.top();

                ans = max(ans, height * width);
            }

            // 將目前棒子的索引放入棧中，維持高度單調遞增
            stk.push(i);
        }
        cout << ans << endl;
    }
}
// 索引：  0  1  2  3
// 高度：  2  4  3  1

// 當處理索引 3、高度 1 時，索引 2 的高度 3 會被彈出。
// 以高度 3 計算矩形
// 被彈出索引：2；目前索引：3
// 左側第一個較矮的棒子：索引 1，高度 4 並不較矮，因此繼續彈出後，才會找到真正的左邊界。
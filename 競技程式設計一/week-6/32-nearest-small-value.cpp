#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    // 使用montonic stack維護遞增棧，棧儲存索引
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // 如果棧頂元素大於當前元素，則彈出棧頂元素，因爲以後的元素都不會以棧頂元素爲答案
        // 至少是a[i]，因爲已知a[stk.top()] >= a[i]，所以a[i]是更小的值
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }
        // 輸出當前棧頂，是最接近i且比i小者
        cout << stk.top() << " ";
        // 入棧
        stk.push(i);
    }
}
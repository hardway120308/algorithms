#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N;

    cin >> N;
    vector<int> A(N);
    // 維持 left 比 right的數量多一或相等
    // C++預設爲最大堆，即使用的比較函數是std::less
    // vector<int>, greater<int>是最小堆
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (left.empty()) {
            // 初始狀況
            left.push(A[i]);
        } else if (A[i] < left.top()) {
            // 如果當前值比left的堆頂（left最大堆）還要小，則進入left
            left.push(A[i]);
        } else {
            // 比left堆頂還大進入right
            right.push(A[i]);
        }
        // 平衡大小
        // 維持left.size() = right.size()+1 or right.size()
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
        cout << left.top() << ' ';
    }
}
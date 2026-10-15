#include <bits/stdc++.h>

using namespace std;
signed main() {
    int Q;
    cin >> Q;
    deque<int> A;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while (Q--) {
        int action;
        cin >> action;
        if (action == 1) {
            int x;
            cin >> x;
            // insert x into A
            A.push_back(x);
        } else if (action == 2) {
            // 如果PQ爲空，則還沒有排序，所以輸出A的front，並將其pop
            // 如果PQ不爲空，即使新增了新的資料也會放在PQ的後尾（還沒有排序），所以輸出PQ的top，並將其pop
            if (minHeap.empty()) {
                cout << A.front() << endl;
                A.pop_front();
            } else {
                cout << minHeap.top() << endl;
                minHeap.pop();
            }
        } else if (action == 3) {
            // 複製A的全部元素到minHeap，過程中將其排序，並清空A
            for (auto x : A) {
                minHeap.push(x);
                A.pop_front();
            }
        }
    }
}
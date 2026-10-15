#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> data(n + k - 1);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    // 爲了circular，在data後面再加上前k-1個元素
    for (int i = 0; i < k - 1; i++) {
        data[n + i] = data[i];
    }

    // Use a deque to maintain the maximum of the current window
    deque<int> Q;
    for (int i = 0; i < data.size(); i++) {
        // 移除不屬於sliding window的元素，即在i-k元素之前
        while (!Q.empty() and Q.front() <= i - k) {
            Q.pop_front();
        }
        // 現在Q的所有元素都是sliding window的元素
        // 維護Q的「單調遞減性」，則Q的隊首必然是sliding window的最大值
        // 讓比當前元素小的元素出隊，因爲它們不可能成爲sliding window的maximum
        while (!Q.empty() and data[Q.back()] < data[i]) {
            Q.pop_back();
        }
        // push當前元素的索引到deque中
        Q.push_back(i);
        if (i >= k - 1) {
            cout << data[Q.front()] << " ";
        }
    }
}
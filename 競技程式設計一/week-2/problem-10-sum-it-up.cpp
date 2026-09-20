#include <bits/stdc++.h>

using namespace std;

int backtrack(int sum, vector<int>& state, vector<int>& nums) {
    int ans = 0;
    if (sum < 0) {
        return 0;
    }
    if (sum == 0) {
        // print state
        for (int i = 0; i < state.size(); i++) {
            int index = state[i];
            cout << to_string(nums[index]) + "+ "[i == state.size() - 1];
        }
        cout << '\n';
        return 1;
    }

    int START = -1;
    if (state.size() >= 1) {
        START = state[state.size() - 1] + 1;
    } else {
        START = 0;
    }

    for (int i = START; i < nums.size(); i++) {
        // 剪枝：同一層選到同一個數字
        // 只跳過「同一層 DFS 中，數值相同的選擇」；不同層仍然可以選相同的數字。
        // 之所以不檢查START，就是讓不同層還是可以選擇相同的數字（已經排序好,相同的數字在附近）
        // 如果是START之後的數字，那他們需要和前一個數字不相同（同一層不重複取相同的數字）
        if (i > START and nums[i] == nums[i - 1])
            continue;
        if (nums[i] > sum)
            continue;
        state.push_back(i);
        ans += backtrack(sum - nums[i], state, nums);
        state.pop_back();
    }
    return ans;
}

signed main() {
    int t, n;
    while (cin >> t >> n) {
        if (t == 0 and n == 0)
            return 0;

        vector<int> nums(n);
        vector<int> state;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << "Sums of " << t << ":\n";
        int ans = backtrack(t, state, nums);
        if (ans == 0) {
            cout << "NONE\n";
        }
    }
    return 0;
}
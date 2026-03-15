#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    int ans = 0;

    // 預處理儲存每個字元的出現位置
    unordered_map<char, vector<int>> loc;
    for (int i = 0; i < n; i++) {
        // 已經預先排序好
        if (loc.count(s[i]) == 0) {
            vector<int> v;
            loc.insert({s[i], v});
        }
        loc[s[i]].push_back(i);
    }

    for (int a = 0; a < 26; a++) {
        auto points = loc['a' + a];

        for (int j = 1; j < points.size(); j++) {
            // 窮舉字母爲a的點j，找出L<=j-i<=R
            // i <= j - L
            // j - r <= i
            // j - r <= i <= j - L
            // 轉換j爲1-based
            int converted_j = points[j];
            // 找到符合L<=j-i的第一個元素在points中的位置
            // lower_bound: 找到第一個大於等於K的元素位置
            // upper_bound: 找到第一個嚴格大於K的元素位置
            // 回傳的是Iterators，需要減去begin才能得到開始值
            // 例如1,2,2,3找2，lower_bound回傳1,upper_bound回傳3
            auto it1 = lower_bound(points.begin(), points.end(), converted_j - r);
            int left_bound = it1 - points.begin();
            // 找到符合j-i<=R的第一個不滿足的元素位置
            auto it2 = upper_bound(points.begin(), points.end(), converted_j - l);
            int right_bound = (it2 - points.begin()) - 1;

            // 如果區間合法
            if (left_bound <= right_bound) {
                ans += (right_bound - left_bound + 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}

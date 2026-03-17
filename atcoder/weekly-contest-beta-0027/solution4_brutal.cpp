#include <bits/stdc++.h>
#include <functional>
#include <numeric>

#define int long long

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    // 所需技能,得到的錢
    vector<pair<int, int>> days;
    for (int i = 0; i < n; i++) {
        int hard_skills, sell;
        cin >> hard_skills >> sell;
        days.push_back({sell, hard_skills});
    }
    vector<int> skills;
    int used[m];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        skills.push_back(x);
    }

    sort(days.begin(), days.end(), std::greater<pair<int, int>>());
    sort(skills.begin(), skills.end());

    int max_sell = 0;
    int now_used_count = 0;

    for (int i = 0; i < n; i++) {
        int need_skill = days[i].second;
        int index = lower_bound(skills.begin(), skills.end(), need_skill) - skills.begin();
        if (index < m) {
            while (used[index]) {
                index++;
                if (index >= m)
                    break;
            }
        }
        if (index < m) {
            if (used[index] == 0) {
                max_sell += days[i].first;
                used[index] = 1;
                now_used_count++;
            } else {
                // 別無選擇，只能不選
            }
        } else {
            // 別無選擇，只能不選
        }
    }

    // 如果有人還沒被用到
    if (now_used_count < m) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << max_sell << endl;
    }

    return 0;
}

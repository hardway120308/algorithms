#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 2e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int q;
    cin >> n >> q;
    // 原本面積
    int TOTAL_AREA = n * n;
    int covered_area = 0;

    // x遞增，y遞減
    map<int, int> mp;
    mp[0] = INF;
    mp[INF] = 0;

    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;

        if (x == 0 || y == 0) {
            cout << TOTAL_AREA - covered_area << "\n";
            continue;
        }

        // 回傳第一個x坐標大於等於map裏面的人
        // 這個人的x坐標>=要加入的x，檢查是否這個人的y坐標>=要加入的y
        // 若是，則被覆蓋，不影響Covered_area
        auto it = mp.lower_bound(x);
        if (it->second >= y) {
            cout << TOTAL_AREA - covered_area << "\n";
            continue;
        }

        // x坐標超過別人，y坐標小於別人
        // 這個別人的y坐標
        int base_y = it->second;

        // 減去那些會被新矩形覆蓋者
        // 從it開始的前一個（令爲cur）開始，每一個的x坐標都小於新加入的矩形
        // 維護y的單調遞減，如果cur的y比新加入的矩形還小，則會被新矩形覆蓋，可以去掉
        auto cur = prev(it);
        // 如果cur的y小於新加入者，則會被覆蓋
        while (cur->second <= y) {
            auto left_it = prev(cur);
            int width = cur->first - left_it->first;
            // 計算和基準所差的麵既
            int height = (cur->second - base_y);
            covered_area -= width * height;
            mp.erase(cur);
            cur = left_it;
        }

        // 現在高於base_y的部分從[x, cur->first]已經被清空
        // 加上新矩形在[x, cur->first]區間高出base_y的面積
        int new_width = x - cur->first;
        covered_area += new_width * (y - base_y);
        mp[x] = y;

        cout << TOTAL_AREA - covered_area << "\n";
    }

    return 0;
}

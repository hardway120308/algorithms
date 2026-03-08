#include <bits/stdc++.h>

using namespace std;

// 不失一般性假設H<=L
// 令CountH=An中小於H的數目
// 令CountL=An中小於L的數目
// 則對於任意合法的格子(x,y)滿足
// 1<=x<=H<=L（假設）
// 1<=y<=L
// 所以，建立一個對須花費CountH-1,CountL-2
// 你可以直接for循環進行CountH-1,CountL-2再把ans輸出
// 或者進行以下估計：令[CountL/2]為向下取整
// 若CountH<=[CountL/2]，則答案為CountH（必有足夠的CountL可以用）
// 若CountH>[CountL/2]，則答案為[CountL/2]（則必有足夠的CountH可以用）
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, l, real_n = 0;
        int count_h = 0;
        int count_l = 0;
        cin >> n >> h >> l;
        if (h > l) {
            swap(h, l);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (1 <= x and x <= h) {
                count_h++;
            }
            if (1 <= x and x <= l) {
                count_l++;
            }
        }
        cout << min(count_h, count_l / 2) << endl;
    }
}

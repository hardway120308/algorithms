#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    while (n--) {
        int y, x;
        cin >> y >> x;
        // layer由max(x,y)決定
        int layer = max(x, y);
        // 奇數層下到上，偶數層相反
        bool is_odd_layer = layer % 2 == 1;
        // 在對角線位置,true代表在上
        bool angle_location = x >= y;
        int start_num = ((layer - 1) * (layer - 1)) + 1;
        int angle_num = start_num + layer - 1;
        if (is_odd_layer) {
            if (angle_location) {
                cout << angle_num + abs(y - layer) << endl;
            } else {
                cout << start_num + x - 1 << endl;
            }
        } else {
            if (angle_location) {
                cout << start_num + y - 1 << endl;
            } else {
                cout << angle_num + abs(x - layer) << endl;
            }
        }
    }
}

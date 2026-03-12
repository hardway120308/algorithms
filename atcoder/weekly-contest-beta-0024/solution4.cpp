#include <bits/stdc++.h>

using namespace std;

// /// Brutal Force 會TLE
// int main() {
//     int n, w, k;
//     cin >> n >> w >> k;

//     int marked[n];
//     memset(marked, 0, sizeof(marked));
//     for (int i = 0; i < k; i++) {
//         int left;
//         cin >> left;
//         // 區間[left,left+w-1]
//         // 數組[left-1,left+w-2]
//         if (w != 1) {
//             for (int j = left - 1; j <= left + w - 2; j++) {
//                 marked[j]++;
//             }
//         } else {
//             marked[left - 1]++;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         cout << marked[i] << " ";
//     }
//     return 0;
// }

/// 使用Imos Trick（放置+1,-1標記）
/// 注意signals必須是n+1大小，因為我們使用+1開始+1，-1的那一格-1（-1的前一個不-1），用來處理[1,1]的狀況
/// 例如：signals：+1,0,0,0,-1(n=4)
/// 則輸出：		1,1,1,1,0(n=4)
int main() {
    int n, w, k;
    cin >> n >> w >> k;

    int signals[n + 1];
    memset(signals, 0, sizeof(signals));

    for (int i = 0; i < k; i++) {
        // 區間：[left, right)
        int left;
        cin >> left;
        left -= 1;
        signals[left]++;
        int right = left + w;
        signals[right]--;
    }
    int x = 0;

    for (int i = 0; i < n; i++) {
        x += signals[i];
        cout << x << " ";
    }

    return 0;
}

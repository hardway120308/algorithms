#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    stack<char> ans;
    cin >> X;

    // 使用棧，如果遇到棧頂是'S'且當前字符是'T'，則彈出棧頂，否則將當前字符入棧
    // 重複整個過程，會將所有的'S'和'T'配對消除，最後棧中剩下的字符就是無法配對的字符
    for (char c : X) {
        if (c == 'T' && !ans.empty() && ans.top() == 'S') {
            ans.pop();
        } else {
            ans.push(c);
        }
    }

    cout << ans.size() << '\n';
}
// 直接對字串進行操作
// 也可以過
// #include <bits/stdc++.h>
// using namespace std;

// signed main() {
//     string X;
//     cin >> X;
//     // 執行n次檢查是否出現ST，有則刪除
//     for (int i = 1; i < X.size(); i++) {
//         if (X[i - 1] == 'S' && X[i] == 'T') {
//             X.erase(i - 1, 2);
//             i -= 2; // 回退兩個位置，因為刪除後可能會出現新的ST
//             if (i < 0)
//                 i = 0; // 防止越界
//         }
//     }
//     cout << X.size() << endl;
// }
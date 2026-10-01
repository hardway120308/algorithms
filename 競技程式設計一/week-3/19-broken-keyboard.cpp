#include <bits/stdc++.h>

using namespace std;

// TLE版本：
// 因爲string concation 的性能消耗非常大，所以會TLE
// signed main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     string S;
//     while (cin >> S) {
//         string result;
//         bool home = false;
//         string home_str;
//         for (auto c : S) {
//             if (c == '[') {
//                 home = true;
//             } else if (c == ']') {
//                 result = home_str + result;
//                 home = false;
//             } else {
//                 if (!home) {
//                     result += c;
//                 } else {
//                     home_str += c;
//                 }
//             }
//         }
//         cout << result << '\n';
//     }
//     return 0;
// }

// 優化版本：使用linked list
// 可以做到O(1)時間內新增刪除

int main() {
    string S;
    while (cin >> S) {
        list<char> text;
        auto it = text.end(); // 初始游標在末端

        for (char c : S) {
            if (c == '[') {
                it = text.begin(); // 切換游標至開頭 (Home)
            } else if (c == ']') {
                it = text.end(); // 切換游標至末端 (End)
            } else {
                text.insert(it, c); // O(1) 插入字元
            }
        }

        // 輸出結果
        for (char c : text) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}

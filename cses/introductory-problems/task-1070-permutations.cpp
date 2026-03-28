// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// bool solved = false;

// void dfs(int n, set<int>& choices, vector<int>& res) {
//     if (res.size() == n) {
//         for (auto p : res) {
//             cout << p << " ";
//         }
//         solved = true;
//         return;
//     }
//     for (auto choice : vector<int>(choices.begin(), choices.end())) {
//         if (res.empty()) {
//             choices.erase(choice);
//             res.push_back(choice);
//             dfs(n, choices, res);
//             res.pop_back();
//             choices.insert(choice);
//         } else {
//             if (abs(res.back() - choice) > 1) {
//                 choices.erase(choice);
//                 res.push_back(choice);
//                 dfs(n, choices, res);
//                 res.pop_back();
//                 choices.insert(choice);
//             }
//         }
//         if (solved) {
//             break;
//         }
//     }
// }

// signed main() {
//     int n;
//     cin >> n;

//     set<int> options;
//     vector<int> res;
//     for (int i = 1; i <= n; i++) {
//         options.insert(i);
//     }
//     dfs(n, options, res);
// }
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    // even numbers
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }

    // odd numbers
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}

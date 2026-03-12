#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    char g[h][w];
    bool is_unique[h][w];
    memset(is_unique, true, sizeof(is_unique));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        unordered_map<char, int> pending;
        for (int j = 0; j < w; j++) {
            if (pending.count(g[i][j]) == 0) {
                pending.insert(make_pair(g[i][j], j));
            } else {
                int dup_j = pending[g[i][j]];
                is_unique[i][dup_j] = false;
                is_unique[i][j] = false;
            }
        }
    }
    for (int j = 0; j < w; j++) {
        unordered_map<char, int> pending;
        for (int i = 0; i < h; i++) {
            if (pending.count(g[i][j]) == 0) {
                pending.insert(make_pair(g[i][j], i));

            } else {
                int dup_i = pending[g[i][j]];
                is_unique[dup_i][j] = false;
                is_unique[i][j] = false;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (is_unique[i][j]) {
                cout << g[i][j];
            }
        }
    }
}
/// 另種方式:針對每行，遍歷各個列找出改行中的字元數目，記為row_count[i][char]=字元數
/// 針對每列，同上
/// 隨後，偏離行，列，如果row_count[i][now_char] = col_count[j][now_char] = 1，則輸出該字元

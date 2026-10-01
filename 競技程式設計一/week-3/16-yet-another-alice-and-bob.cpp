#include <bits/stdc++.h>
using namespace std;

// 每過一秒，r + c 一定增加 1。
// 初始在 (1,1)，時間 0，所以時間 t 時 r + c = t + 2。
// 所以如果r相同，且t相同，則c必相同
// 同一格 (r,c) 的 r+c 固定，所以兩人若都經過它，到達時間必相同。
// 因此交集格子全部是紫色。
// 每人各走 N 步，且每步都到新格子，所以紅 = N - 紫，藍 = N - 紫。

struct Seg {
    long long l, r;       // 移動秒數區間 [l, r]
    int dir;              // 0 = right, 1 = down
    long long row_before; // 此段開始前，也就是 l-1 秒時的列號
};

/// @brief 由給定的A/B陣列建立多個線段
/// @param turns A/B陣列
/// @param initDir 開始的方向（Right/Down）
/// @param N 總共走的格子數
/// @return 線段陣列
vector<Seg> build(const vector<long long>& turns, int initDir, long long N) {
    vector<Seg> segs;
    long long cur = 1;
    int dir = initDir;
    long long row = 1;

    for (long long t : turns) {
        if (t > cur) {
            segs.push_back({cur, t - 1, dir, row});
            if (dir == 1)
                row += (t - cur); // 向下，列號增加
            cur = t;
        }
        dir ^= 1; // 右 <-> 下 切換
    }

    if (cur <= N) {
        segs.push_back({cur, N, dir, row});
    }
    return segs;
}

long long countPurple(const vector<Seg>& A, const vector<Seg>& B) {
    long long i = 0, j = 0;
    long long ans = 0;

    // 需要走過A,B的每一個線段
    while (i < (long long)A.size() && j < (long long)B.size()) {
        // 找出兩個Seg的重疊邊界[L,R]（秒）
        long long L = max(A[i].l, B[j].l);
        long long R = min(A[i].r, B[j].r);

        if (L <= R) {
            // 在 L 秒時，兩人的列號
            // 如果A/B是向下的話，則L秒的列號會是A/B的l-1秒的列號 + (A或B的l爲開始，L爲結尾的區間長)
            long long rowA = A[i].row_before + (A[i].dir == 1 ? (L - A[i].l + 1) : 0);
            long long rowB = B[j].row_before + (B[j].dir == 1 ? (L - B[j].l + 1) : 0);

            // 根據 R+C=T+2 這個等式，我們只要確保R,T相同，則A,B會在該點交會
            // 我們只需要找到列相等的點即可，兩個線段最多只會交會一次
            // find rowA + rateA * (t - L) = rowB + rateB * (t - L)
            // i.e (rateA - rateB) * (t - L) = rowB - rowA
            // let rateDiff = rateA - rateB and diff = rowA - rowB
            // Then the equation can be written as:
            // rateDiff * (t-L) + diff = 0

            // 向下時列號每秒 +1
            long long rateA = (A[i].dir == 1);
            long long rateB = (B[j].dir == 1);

            long long diff = rowA - rowB;
            long long rateDiff = rateA - rateB;

            if (rateDiff == 0) {
                // 若列不移動且初始diff不是0，則永遠不會相碰
                if (diff == 0)
                    // 在同一個列，而且都往右邊移動
                    // 所以purple加上[L,R]區間的長度
                    ans += (R - L + 1);
            } else if (rateDiff == 1) {
                // diff + (t - L) = 0
                // 確保t belong to [L,R]則他們在t秒相碰
                if (diff <= 0) {
                    long long t = L - diff;
                    if (t <= R)
                        ++ans;
                }

            } else { // rateDiff == -1
                // diff - (t - L) = 0
                // 確保t belong to [L,R]則他們在t秒相碰
                if (diff >= 0) {
                    long long t = L + diff;
                    if (t <= R)
                        ++ans;
                }
            }
        }

        // 如果A的左邊小於B的左邊界，則移動A的下一個seg
        if (A[i].r < B[j].r)
            ++i;
        // 反之，則移動B的下一個seg
        else if (B[j].r < A[i].r)
            ++j;
        // 如果A和B的左邊界相同，則都移動到下一個seg
        else {
            ++i;
            ++j;
        }
    }

    return ans;
}

int main() {
    long long N;
    int A, B;
    cin >> N >> A >> B;

    vector<long long> ta(A), tb(B);
    for (int i = 0; i < A; ++i)
        cin >> ta[i];
    for (int i = 0; i < B; ++i)
        cin >> tb[i];

    // Alice 初始向右，Bob 初始向下
    vector<Seg> sa = build(ta, 0, N);
    vector<Seg> sb = build(tb, 1, N);

    long long purple = countPurple(sa, sb);
    long long red = N - purple;
    long long blue = N - purple;

    cout << red << ' ' << blue << ' ' << purple << '\n';
    return 0;
}
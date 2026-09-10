#include "bits/stdc++.h"
#define int long long
using namespace std;

struct pop {
    int r;
    int c;
    int peoples;
};

int global_d = 1e18;
vector<int> best;

int distance(int r1, int c1, int r2, int c2) { return abs(r1 - r2) + abs(c1 - c2); }

void dfs(vector<int>& state, vector<pop>& pops) {
    if (state.size() == 5) {
        // 計算結果

        int d = 0;
        for (auto p : pops) {
            int d_local = 1e9 + 7;
            for (auto office : state) {
                int office_r = office / 5;
                int office_c = office % 5;

                d_local = min(d_local, distance(office_r, office_c, p.r, p.c));
            }
            d += d_local * p.peoples;
        }
        if (d < global_d) {
            best = state;
            global_d = d;
        }
        return;
    }

    // combinaation: c25取5
    int start = 0;
    if (state.size() >= 1) {
        start = state.back() + 1;
    }
    for (int i = start; i < 25; i++) {
        state.push_back(i);
        dfs(state, pops);
        state.pop_back();
    }
}

signed main() {
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pop> pops;
        vector<int> state;
        for (int i = 0; i < n; i++) {
            int r, c, peoples;
            cin >> r >> c >> peoples;
            pop a = pop{r, c, peoples};
            pops.push_back(a);
        }

        dfs(state, pops);

        for (int i = 0; i < best.size(); i++) {
            cout << best[i] << " \n"[i == 4];
        }
        global_d = 1e10 + 7;
    }
    return 0;
}
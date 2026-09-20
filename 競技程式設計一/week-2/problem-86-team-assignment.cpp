#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N, K;
int teamSize;

vector<ll> a;

ll ans = LLONG_MIN;

// 選目前這一隊還需要的士兵
//
// pos         ：從 candidates 的哪個位置開始選
// need        ：還需要選幾個人
// sum         ：目前這一隊的總戰力
// mask        ：已經使用哪些士兵
// teams       ：目前已經完成幾隊
// product     ：前面幾隊的總戰力乘積
// candidates  ：目前可以選的士兵
void choose(int pos, int need, ll sum, int mask, int teams, ll product, vector<int>& candidates) {
    // 這一隊選完了
    if (need == 0) {

        // 繼續組下一隊
        dfs(mask, teams + 1, product * sum);

        return;
    }

    // 還需要選人
    for (int i = pos; i < candidates.size(); i++) {

        int x = candidates[i];

        choose(i + 1, need - 1, sum + a[x], mask | (1 << x), teams, product, candidates);
    }
}

// 組隊
void dfs(int mask, int teams, ll product) {
    // 所有隊伍都完成
    if (teams == K) {
        ans = max(ans, product);
        return;
    }

    // 找出編號最小的、還沒有使用的士兵
    int first = -1;

    for (int i = 0; i < N; i++) {
        // 找到還沒有visited的
        if (!(mask & (1 << i))) {
            first = i;
            break;
        }
    }

    // first 必須放進這一隊
    int newMask = mask | (1 << first);

    ll sum = a[first];

    // 找出其他還沒使用的人
    vector<int> candidates;

    for (int i = first + 1; i < N; i++) {

        if (!(mask & (1 << i))) {
            candidates.push_back(i);
        }
    }

    // 已經有 first
    // 還需要 teamSize - 1 個人
    choose(0, teamSize - 1, sum, newMask, teams, product, candidates);
}

int main() {
    // 流程：dfs進行組隊（找到第一個人）->使用choose找其他人到填滿人員並更新狀態->chosse呼叫dfs組下一個隊伍->choose->dfs->...
    cin >> N >> K;

    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    teamSize = N / K;

    dfs(0, 0, 1);

    cout << ans << '\n';
}
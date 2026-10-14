#include <bits/stdc++.h>

using namespace std;
int binarySearch(int L ,int R);
bool check() {
    
}
bool check2(int m, int k,vector<pair<int,int>>& horses, vector<int>& C)

{
    int win = 0;
    
    for (auto opponent: C) {
        int min_trained_days = binarySearch(0,m);
        if (win >=k) return true;
    }

    return false;
}

int binarySearch(int L,int R) {
    while (L<R) {
        int mid = L + (L+R)/2;
        if (check(mid)) {
            R=mid;
        } else {
            L=mid+1;
        }
    }
    return L;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> horses(N);
        vector<int> C(N);
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            horses[i] = {a, b};
        }
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }
        sort(horses.begin(), horses.end());
        sort(C.begin(),C.end());
    }
}

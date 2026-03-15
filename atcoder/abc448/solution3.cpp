#include "bits/stdc++.h"

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int, long long int>> A;
    for (int i = 0; i < N; i++) {
        long long int x;
        cin >> x;
        A.push_back({x, i + 1});
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < Q; i++) {
        int K;
        cin >> K;
        set<int> B;
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            B.insert(x);
        }
        long long int ans = 0;
        for (int j = 0; j < K + 1; j++) {
            if (B.count(A[j].second) == 0) {
                ans = A[j].first;
                break;
            }
        }
        cout << ans << endl;
    }
}

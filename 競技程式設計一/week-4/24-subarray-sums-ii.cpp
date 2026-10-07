#include <bits/stdc++.h>
using namespace std;

// 1-based
signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> V(n+1);
    vector<int> prefix_sum(n+1);
    prefix_sum[0]=0;
    for (int i = 1; i <= n; i++) {;
        cin >> V[i];
        prefix_sum[i]=prefix_sum[i-1]+V[i];
        
    }

    int left=1;
    int right=left+1;

    while (left <= right and left <= n and right <= n) {
        int sum = prefix_sum[right]-prefix_sum[left-1]
    }
}

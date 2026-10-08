#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, K;

bool check(vector<int>& A, int maxSum) {
    int nowSum = 0;
    int k = 1;
    for (auto num : A) {
        if (num > maxSum) {
            return false;
        }
        nowSum += num;
        if (nowSum > maxSum) {
            nowSum = num;
            k++;
        }

        if (k > K) {
            return false;
        }
    }
    return true;
}

/// 回傳第一個為true的index
int binarySearch(vector<int>& A, int L, int R) {
    while (L < R) {
        int mid = L + (R - L) / 2;
        if (check(A, mid)) {
            R = mid;
        } else {
            // because check(A,mid)==false
            L = mid + 1;
        }
    }

    return L;
}

/// 回傳(L,R)
/// T,T,T,F,F,F
pair<int, int> binarySearch_v2(vector<int>& A, int L, int R) {
    // 邊界條件
    if (check(A, L)) {
        // F,T
        return {L - 1, L};
    }
    if (check(A, R)) {
        // T,T
        return {R, R + 1};
    }
    while (L < R) {
        int mid = L + (R - L) / 2;
        if (check(A, mid)) {
            R = mid;
        } else {
            // because check(A,mid)==false
            L = mid;
        }
    }

    return {L, R};
}

signed main() {
    cin >> N >> K;
    vector<int> A(N);
    int max_element = -1;
    int total_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total_sum += A[i];
        max_element = max(A[i], max_element);
    }

    // for (int i = 0; i <= total_sum; i++) {
    //     cout << "Check:" << i << ' ' << check(A, i) << '\n';
    // }

    cout << binarySearch(A, max_element, total_sum);
}
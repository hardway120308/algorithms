#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<long long> candidates;

    long long M = A.back(); // max(A)

    // 情況一：L = M (有至少一根沒斷裂)
    {
        vector<long long> small;
        for (auto x : A) {
            if (x < M)
                small.push_back(x);
        }

        bool ok = (small.size() % 2 == 0);
        if (ok) {
            int left = 0, right = (int)small.size() - 1;
            while (left < right) {
                if (small[left] + small[right] != M) {
                    ok = false;
                    break;
                }
                left++;
                right--;
            }
        }
        if (ok) {
            candidates.push_back(M);
        }
    }

    // 情況二：全部都斷裂 (N 為偶數)
    if (N % 2 == 0) {
        long long L = A[0] + A.back();
        if (L > M) { // 必須嚴格大於 max
            bool ok = true;
            for (int i = 0; i < N / 2; i++) {
                if (A[i] + A[N - 1 - i] != L) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                candidates.push_back(L);
            }
        }
    }

    // 去除重複並排序後輸出
    sort(candidates.begin(), candidates.end());
    auto it = unique(candidates.begin(), candidates.end());
    candidates.resize(it - candidates.begin());

    for (size_t i = 0; i < candidates.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << candidates[i];
    }
    cout << endl;

    return 0;
}

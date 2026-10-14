#include <bits/stdc++.h>

using namespace std;

/// 判斷avg是否可以被兩個陣列的前綴和所達成 \n
/// 方法為先讓a陣列每個值減去avg，b陣列每個值減去avg，然後計算兩個陣列的前綴和，找出最大的前綴和，如果兩個最大前綴和的總和大於等於0，則表示avg可以被達成(平均數線性平移)
pair<int, int> check(vector<double>& a, vector<double>& b, double avg) {
    vector<double> prefix_sum_a(a.size() + 1, 0), prefix_sum_b(b.size() + 1, 0);
    // 尋找在avg的限制下，最大的PrefSumA和PrefSumB的index
    int maxPrefSumAIndex = 1, maxPrefSumBIndex = 1;
    for (int i = 0; i < a.size(); i++) {
        prefix_sum_a[i + 1] = prefix_sum_a[i] + (a[i] - avg);
        prefix_sum_b[i + 1] = prefix_sum_b[i] + (b[i] - avg);
        if (prefix_sum_a[i + 1] > prefix_sum_a[maxPrefSumAIndex]) {
            maxPrefSumAIndex = i + 1;
        }
        if (prefix_sum_b[i + 1] > prefix_sum_b[maxPrefSumBIndex]) {
            maxPrefSumBIndex = i + 1;
        }
    }

    if (prefix_sum_a[maxPrefSumAIndex] + prefix_sum_b[maxPrefSumBIndex] >= 0) {
        return {maxPrefSumAIndex, maxPrefSumBIndex};
    } else {
        return {-1, -1};
    }
}

pair<int, int> binarySearch(vector<double>& a, vector<double>& b, double L, double R, double eps = 1e-7) {
    int i, j = 0;
    while (L + eps < R) {
        double mid = L + (R - L) / 2;
        auto [r_i, r_j] = check(a, b, mid);
        if (r_i != -1) {
            L = mid;
            i = r_i;
            j = r_j;
        } else {
            R = mid;
        }
    }
    return {i, j};
}

signed main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    double maxElement = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxElement = max(maxElement, a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        maxElement = max(maxElement, b[i]);
    }

    auto [i, j] = binarySearch(a, b, 0, maxElement);
    cout << i << " " << j << endl;
}
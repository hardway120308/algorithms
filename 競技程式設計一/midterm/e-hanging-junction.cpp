#include <bits/stdc++.h>
#define pii pair<int, int>
#define double long double
#define pdd pair<double, double>
using namespace std;

double distance(pdd a, pdd b) {
    double item1 = (a.first - b.first) * (a.first - b.first);
    double item2 = (a.second - b.second) * (a.second - b.second);
    return sqrt(item1 + item2);
}

double f(vector<int>& X, pdd P) {
    double res = 0.0;
    for (auto x : X) {
        res += distance({x, 0}, P);
    }
    return res;
}

double tripleSearch(pdd left, pdd right, vector<int>& X, double eps = 1e-9) {
    double f_val = f(X, left);
    while (distance(left, right) > eps) {
        double mid1_x = left.first + (right.first - left.first) / 3.0;
        double mid1_y = left.second + (right.second - left.second) / 3.0;
        double mid2_x = left.first + (right.first - left.first) / 3.0 * 2.0;
        double mid2_y = left.second + (right.second - left.second) / 3.0 * 2.0;

        double f_mid1 = f(X, {mid1_x, mid1_y});
        double f_mid2 = f(X, {mid2_x, mid2_y});

        if (f_mid1 < f_mid2) {
            right = {mid2_x, mid2_y};
        } else {
            left = {mid1_x, mid1_y};
        }

        f_val = f(X, left);
    }
    return f_val;
}

signed main() {
    int N;
    cin >> N;
    pair<double, double> A, B;
    cin >> A.first >> A.second >> B.first >> B.second;
    vector<int> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    cout << fixed << setprecision(10) << tripleSearch(A, B, points) << '\n';
}

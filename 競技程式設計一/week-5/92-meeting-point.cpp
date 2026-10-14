#include <bits/stdc++.h>
using namespace std;

double dist(double x, double a, double b, double X) {
    double d = abs(x - X);
    return a * d * d + b * d;
}

// Calucate the last person arrives time when they meet at X
double f(vector<double>& x, vector<double>& a, vector<double>& b, double X) {
    double y = -10.0;
    for (int i = 0; i < x.size(); i++) {
        y = max(dist(x[i], a[i], b[i], X), y);
    }
    return y;
}

// 三分法: minimizes the time when the last person arrives
double tripleSearch(vector<double>& x, vector<double>& a, vector<double>& b, double L, double R, double eps = 1e-7) {
    while (L + eps < R) {
        double mid = L + (R - L) / 3;
        double mid2 = L + (R - L) / 3 * 2;
        if (f(x, a, b, mid) < f(x, a, b, mid2)) {
            R = mid2;
        } else {
            L = mid;
        }
        // cout << " f(mid1) " << f(x, a, b, mid) << " f(mi2) " << f(x, a, b, mid2) << " L is :" << L << " R is: " << R
        //  << '\n';
    }
    return L;
}

signed main() {
    int n;
    cin >> n;
    vector<double> x(n), a(n), b(n);
    double maxX = -1;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> a[i] >> b[i];
        maxX = max(x[i], maxX);
    }
    cout << tripleSearch(x, a, b, 0, maxX) << '\n';
}
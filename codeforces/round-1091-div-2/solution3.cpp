#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;

        if (std::gcd(n, a) == 1 && std::gcd(m, b) == 1 && std::gcd(n, m) <= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

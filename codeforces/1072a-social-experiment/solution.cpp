#include <bits/stdc++.h>

using namespace std;
int answer = INT_MAX;
int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << 2 << endl;
        } else if (n == 3) {
            cout << 3 << endl;
        } else {
            cout << n % 2 << endl;
        }
    }
    return 0;
}

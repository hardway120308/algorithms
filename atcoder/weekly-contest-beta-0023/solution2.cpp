#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[n], b[n - 1];
    long long int passengers = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> a[n - 1];
    for (int i = 0; i < n; i++) {
        passengers += a[i];
        if (i != n - 1) {
            long long int leave_count = min(passengers, b[i]);
            passengers -= leave_count;
        } else {
            break;
        }
    }
    cout << passengers << endl;
    return 0;
}

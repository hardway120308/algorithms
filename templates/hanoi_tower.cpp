#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char to, char tmp) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << '\n';
        return;
    }

    // Step 1: move n-1 disks to tmp
    hanoi(n - 1, from, tmp, to);

    // Step 2: move largest disk
    cout << "Move disk " << n << " from " << from << " to " << to << '\n';

    // Step 3: move n-1 disks to target
    hanoi(n - 1, tmp, to, from);
}

int main() {
    int n;
    cin >> n;

    hanoi(n, 'A', 'C', 'B');

    return 0;
}

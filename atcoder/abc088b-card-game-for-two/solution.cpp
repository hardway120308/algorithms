#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int alice = 0;
    int bob = 0;
    cin >> n;
    vector<int> an;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        an.push_back(a);
    }
    sort(an.begin(), an.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 1) {
            alice += an[i];
        } else {
            bob += an[i];
        }
    }

    cout << alice - bob << endl;

    return 0;
}

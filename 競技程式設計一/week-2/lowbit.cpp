#include <bitset>
#include <iostream>
using namespace std;
int lowbit(int x) { return x & -x; }
int main() {
    int S = 0b100011000;
    cout << bitset<32>(S) << endl;
    while (S) {
        int lb = lowbit(S);
        cout << lb << '\n';
        S -= lb;
    }
    return 0;
}
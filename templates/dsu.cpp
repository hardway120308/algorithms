#include <bits/stdc++.h>

using namespace std;

int parent[50000];

int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

bool unite(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);
    parent[root1] = root2;

    return true;
}

signed main() {
    cout << "Hello World" << endl;
    return 0;
}
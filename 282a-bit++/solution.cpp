#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    while (n--) {
        string prompt;
        cin >> prompt;
        // Starts with OPERATION
        if (prompt[0] == '+' or prompt[0] == '-') {
            if (prompt[0] == '+') {
                x += 1;
            } else {
                x -= 1;
            }
        }
        // End with OPERATION
        else {
            if (prompt[prompt.length() - 1] == '+') {
                x += 1;
            } else {
                x -= 1;
            }
        }
    }

    cout << x << endl;

    return 0;
}

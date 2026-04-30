#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        stack<int> m_2;
        stack<int> m_3;
        stack<int> m_6;
        stack<int> others;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 6 == 0) {
                m_6.push(a[i]);
            } else if (a[i] % 3 == 0) {
                m_3.push(a[i]);
            } else if (a[i] % 2 == 0) {
                m_2.push(a[i]);
            } else {
                others.push(a[i]);
            }
        }
        while (!m_6.empty()) {
            cout << m_6.top() << " ";
            m_6.pop();
        }
        while (!m_3.empty()) {
            cout << m_3.top() << " ";
            m_3.pop();
        }

        while (!others.empty()) {
            cout << others.top() << " ";
            others.pop();
        }
        while (!m_2.empty()) {
            cout << m_2.top() << " ";
            m_2.pop();
        }
        cout << endl;
    }
}

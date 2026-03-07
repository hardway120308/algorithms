#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        string s;
        cin >> s;
        bool is_dup = false;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                is_dup = true;
                break;
            }
        }
        if (is_dup)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << s.length() << endl;
        }
    }
}
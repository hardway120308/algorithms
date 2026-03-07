#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        int pn[n];
        int l = -1;
        int r = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> pn[i];
            if (pn[i] == n - i)
            {
                continue;
            }
            else
            {
                if (l == -1)
                {
                    l = i;
                }
                else
                {
                    if (pn[i] == n - l)
                    {
                        r = i;
                    }
                }
            }
        }

        if (l == -1 and r == -1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << pn[i] << " ";
            }
        }
        else
        {

            for (int i = 0; i < l; i++)
            {
                cout << pn[i] << " ";
            }
            for (int j = r; j >= l; j--)
            {
                cout << pn[j] << " ";
            }
            for (int k = r + 1; k < n; k++)
            {
                cout << pn[k] << " ";
            }
        }

        cout << endl;
    }
}

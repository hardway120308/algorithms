#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int ans = 0;
    cin >> n;

    while (n--)
    {
        int right_number = 0;

        for (int i = 0; i < 3; i++)
        {
            int can_solve;
            cin >> can_solve;
            if (can_solve)
            {
                right_number++;
            }
        }
        if (right_number >= 2)
        {
            ans++;
        }
    }
    cout << ans;
}
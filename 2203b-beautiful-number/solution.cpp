#include <bits/stdc++.h>

using namespace std;

vector<int> diffs;

int f(string x)
{
    int sum = 0;
    for (int i = 0; i < x.length(); i++)
    {
        auto c = x[i];

        int digit = atoi(&c);
        sum += digit;
        if (i == 0)
        {
            diffs.push_back(digit - 1);
        }
        else
        {
            diffs.push_back(digit);
        }
    }
    return sum;
}

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int ans = 0;
        string x;
        cin >> x;
        int now_fx = f(x);
        if (now_fx <= 9)
        {
            cout << 0 << endl;
        }
        else
        {
            const int NEEDED_FX = 9;
            sort(diffs.begin(), diffs.end(), std::greater<int>());
            for (int i = 0; i < diffs.size(); i++)
            {
                now_fx -= diffs[i];
                ans++;
                if (now_fx <= NEEDED_FX)
                {
                    break;
                }
            }
            cout << ans << endl;
        }
        diffs.clear();
    }
    return 0;
}
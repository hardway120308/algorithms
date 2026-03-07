#include <iostream>
#include <vector>
using namespace std;
/// 給定任一個序列:
/// 已經為遞增，答案為n
/// 非遞增，則必存在兩個相鄰元素使得其為遞減子序列，保留他們刪除其他所有元素，最後必可得到長度為1的序列
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool non_decreasing = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                non_decreasing = false;
                break;
            }
        }

        if (non_decreasing)
            cout << n << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}
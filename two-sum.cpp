#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> x;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int num1 = nums[i];
            int num2 = target - num1;
            if (x.count(num2))
            {
                ans.push_back(i);
                ans.push_back(x[num2]);
                break;
            }
            x.insert({nums[i], i});
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int num1 = INT_MIN;
        int num2 = INT_MIN;

        int cnt1 = 0;
        int cnt2 = 0;

        for (int num : nums)
        {
            if (num1 == num)
            {
                cnt1++;
            }
            else if (num2 == num)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                num1 = num;
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                num2 = num;
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums)
        {
            if (num == num1)
            {
                cnt1++;
            }
            else if (num == num2)
            {
                cnt2++;
            }
        }
        int n = nums.size();
        int cnt = floor(n / 3) + 1;

        if (cnt1 >= cnt && cnt2 >= cnt)
            return {num1, num2};
        else if (cnt1 >= cnt)
        {
            return {num1};
        }
        else if (cnt2 >= cnt)
        {
            return {num2};
        }
        else
        {
            return {};
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}
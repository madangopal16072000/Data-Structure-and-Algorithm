#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int cnt = 0;
        int elem = 0;

        for (int num : nums)
        {
            if (cnt == 0)
            {
                elem = num;
                cnt++;
            }
            else if (num == elem)
                cnt++;
            else
                cnt--;
        }
        return elem;
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
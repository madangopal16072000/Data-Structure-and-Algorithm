#include<bits/stdc++.h>
using namespace std;


vector<int> LDS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    unordered_map<int, int> mp;

    int maxSize = 1;
    int lastIdx = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        mp[i] = i;
        for(int j = 0; j < i; j++)
        {
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                mp[i] = j;
            }
        }
        if(maxSize < dp[i])
        {
            maxSize = dp[i];
            lastIdx = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIdx]);

    while(mp[lastIdx] != lastIdx)
    {
        lastIdx = mp[lastIdx];
        temp.push_back(nums[lastIdx]);
    }
    reverse(temp.begin(), temp.end());
    return temp;

}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    vector<int> ans = LDS(nums);
    for(int x : nums)
    cout << x << " ";
    return 0;
}
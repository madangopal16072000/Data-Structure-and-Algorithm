#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 1;
            if (!pq.empty() && pq.top().second == nums[i])
            {
                pair<int, int> p = pq.top();
                cnt = p.first;
                cnt++;
                pq.pop();
            }
            pq.push({cnt, nums[i]});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    int k;
    cin >> k;
    Solution sln;
    vector<int> ans = sln.topKFrequent(nums, k);
    for (int x : ans)
        cout << x << " ";
    return 0;
}
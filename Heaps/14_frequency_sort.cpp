#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(pair<int, int> &b, pair<int, int> &a)
    {
        if (b.first < a.first)
            return true;
        else if (b.first == a.first && b.second > a.second)
            return true;

        return false;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int d;
            cin >> d;
            nums.push_back(d);
        }

        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (auto p : mp)
        {
            pq.push({p.second, p.first});
        }

        while (!pq.empty())
        {
            int cnt = pq.top().first;
            int val = pq.top().second;
            pq.pop();
            while (cnt > 0)
            {
                cout << val << " ";
                cnt--;
            }
        }
        cout << endl;
    }
    return 0;
}
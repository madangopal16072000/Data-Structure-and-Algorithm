#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second; // sort by second element in descending order
        }
        else
        {
            return a.first < b.first; // sort by first element in descending order
        }
    }
};
class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(vector<Job> arr, int n)
    {
        // your code here
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({arr[i].dead, arr[i].profit});
        }

        int time = pq.top().first;
        int ans = pq.top().second;
        int cnt = 1;
        time--;
        while (!pq.empty() && time)
        {
            int d = pq.top().first;
            int p = pq.top().second;
            pq.pop();

            if (d < cnt)
                continue;

            time--;
            cnt++;
            ans = ans + p;
        }

        return {cnt, ans};
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<Job> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id, d, p;
        cin >> id >> d >> p;
        Job j = {id, d, p};
        arr.push_back(j);
    }

    Solution sln;
    vector<int> ans = sln.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
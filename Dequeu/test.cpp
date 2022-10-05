#include <bits/stdc++.h>
using namespace std;
int numberOfWeakCharacters(vector<vector<int>> &properties)
{
    deque<vector<int>> dq;
    sort(properties.begin(), properties.end());
    for (vector<int> row : properties)
    {
        dq.push_back(row);
    }

    int ans = 0;
    for (int i = 1; i < dq.size(); i++)
    {
        int j = 0;
        while(j < i)
        {
            if (dq[i][0] > dq[j][0] && dq[i][1] > dq[j][1])
            {
                ans++;
                dq.pop_front();
                i--;
            }
            else
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> dq{{7, 7}, {1, 2}, {9, 7}, {7, 3}, {3, 10}, {9, 8}, {8, 10}, {4, 3}, {1, 5}, {1, 5}};
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++)
    // {
    //     vector<int> row;
    //     for(int j = 0; j < 2; j++)
    //     {
    //         int d;
    //         cin >> d;
    //         row.push_back(d);
    //     }
    //     dq.push_back(row);
    // }
    cout << numberOfWeakCharacters(dq) << endl;
    return 0;
}

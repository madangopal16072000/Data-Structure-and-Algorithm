#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int amount = 0;
        int N = cost.size();
        int start = 0;
        // for(int i = 1; i < cost.size(); i++)
        // {
        //     if(cost[i] < cost[start])
        //     {
        //         start = i;
        //     }
        //     else if(cost[i] == cost[start])
        //     {
        //         if(gas[i] > gas[start])
        //         {
        //             start = i;
        //         }
        //         else if(gas[i] == gas[start])
        //         {
        //             if(cost[(i+1)%N] < cost[(start+1)%N])
        //             {
        //                 start = i;
        //             }
        //         }
        //     }
        //
        for(start = 0; start < N; start++)
        {
            int i = 0;
            amount = gas[start];
            if(amount - cost[start] >= 0)
            {
                amount = amount-cost[start] + gas[(start+1)%N];
                i = (start+1)%N;
            }
            else
            continue;

            while(i != start)
            {
                if(amount-cost[i] >= 0)
                {
                    amount = amount-cost[i] + gas[(i+1)%N];
                    i = (i+1)%N;
                }
                else
                break;
            }
            return start;
        }
        return -1;
        
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
  vector<int> gas, cost;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    gas.push_back(d);
  }

  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    cost.push_back(d);
  }

  Solution sln;
  cout << sln.canCompleteCircuit(gas, cost) << endl;
  return 0;
}
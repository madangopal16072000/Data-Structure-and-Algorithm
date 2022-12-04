#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    long long jumpingNums(long long X)
    {
        int r;
        long long n = X;
        vector<int> nums;
        while(n)
        {
            r = n%10;
            nums.push_back(r);
            n = n/10;
        }
        int first = nums[nums.size()-1];

        queue<long long> q;
        q.push(first-1);
        q.push(first);
        long long ans = INT_MIN;

        while(!q.empty())
        {
            long long m = q.front();
            q.pop();
            if(m <= X)
            {
                ans = max(ans, m);

                int lastDigit = m%10;

                if(lastDigit == 0)
                {
                    q.push(m*10 + lastDigit + 1);
                }
                else if(lastDigit == 9)
                {
                    q.push(m*10 + lastDigit - 1);
                }
                else
                {
                    q.push(m*10 + lastDigit - 1);
                    q.push(m*10 + lastDigit + 1);
                }
            }
        }
        return ans;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  long long X = 50;
  Solution sln;
  cout << sln.jumpingNums(X) << endl;
  return 0;
}
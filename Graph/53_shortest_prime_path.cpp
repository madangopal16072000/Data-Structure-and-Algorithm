#include <bits/stdc++.h>
using namespace std;
#define N 10000
class Solution
{
public:
    int *prime;
    Solution()
    {
        prime = new int[N];
        for(int i = 0; i<= N; i++)
        prime[i] = 0;

        for (int i = 3; i <= N; i = i + 2)
            prime[i] = 1;

        for (int i = 3; i <= N; i = i + 2)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j <= N; j = j + i)
                    prime[i] = 0;
            }
        }
        prime[1] = prime[0] = 0;
        prime[2] = 1;
    }
    vector<int> ext(int num)
    {
        vector<int> ans;

        while (num)
        {
            int r = num % 10;
            num = num / 10;
            ans.push_back(r);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int vecToInt(vector<int> num)
    {
        int n = 0;
        for (int i = 0; i < num.size(); i++)
        {
            n = num[i] + n * 10;
        }
        return n;
    }
    int shortestPath(int Num1, int Num2)
    {
        // Complete this function using prime vector

        queue<pair<vector<int>, int>> q;
        vector<int> temp = ext(Num1);
        q.push({temp, 0});
        vector<int> temp2 = ext(Num2);
        while (!q.empty())
        {
            vector<int> temp = q.front().first;
            int step = q.front().second;
            q.pop();
            if (vecToInt(temp) == Num2)
            {
                return step;
            }

            for (int i = 0; i <= 3; i++)
            {
                int val = temp[i];
                for (int j = 0; j <= 9; j++)
                {

                    if(i == 0 && j == 0)
                    continue;

                    if(val == j)
                    continue;

                    temp[i] = j;
                    int num = vecToInt(temp);

                    if (prime[num] == 1 && num <= Num2)
                    {
                        q.push({temp, step + 1});
                    }
                }
                temp[i] = val;
            }
        }

        return -1;
    }
};
int main()
{
    int Num1 = 1033, Num2 = 8179;
    Solution sln;
    cout << sln.shortestPath(Num1, Num2) << endl;
    return 0;
}
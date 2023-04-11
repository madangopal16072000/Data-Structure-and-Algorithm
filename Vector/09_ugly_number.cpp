#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {

        if (n == 1)
            return 1;

        int j = 2;
        n = n - 1;

        while (n > 0)
        {
            int i = j;

            while ((i % 2) == 0)
            {
                i = i / 2;
            }

            while ((i % 3) == 0)
                i = i / 3;

            while ((i % 5) == 0)
                i = i / 5;

            if (i == 1)
            {
                n--;
            }
            j++;
        }
        return j - 1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n = 10;
    Solution sln;
    cout << sln.nthUglyNumber(n) << endl;
    return 0;
}
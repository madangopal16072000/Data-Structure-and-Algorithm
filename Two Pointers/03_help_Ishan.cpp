#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPrime(int N)
    {
        for (int i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
                return false;
        }
        return true;
    }
    int NthTerm(int N)
    {
        // Code here
        if (isPrime(N))
            return 0;
        int i = N + 1;
        int j = N - 1;
        while (!isPrime(i) && !isPrime(j))
        {
            i++;
            j--;
        }
        if (isPrime(i))
        {
            return abs(N-i);
        }
        else
            return abs(N-j);
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("./input.txt", "r", stdin);
//     freopen("./output.txt", "w", stdout);
// #endif
    int N;
    N = 10;
    Solution sln;
    cout << sln.NthTerm(N) << endl;
    return 0;
}
#include<iostream>
using namespace std;

int ladders_bottomUp(int N, int K)
{
    int dp[100] = {0};
    dp[0] = 1;

    for(int i = 1; i <=N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            if(i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[N];
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << ladders_bottomUp(N, K) << endl;
    return 0;
}
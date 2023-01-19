#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long numOfWays(int N, int M)
{
    // write code here
    
    int drow[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dcol[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int cnt = 0;
            for(int k = 0; k < 8; k++)
            {
                int r = i + drow[k];
                int c = j + dcol[k];
                
                if(r < N && r >= 0 && c < M && c >= 0)
                {
                    cnt++;
                }
                
                
            }
            ans = (ans + (N*M - (cnt+1))%MOD)%MOD;
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int N, M;
  cin >> N >> M;

  cout << numOfWays(N, M) << endl;
  return 0;
}
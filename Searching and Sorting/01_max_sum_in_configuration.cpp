#include<bits/stdc++.h>
using namespace std;
int max_sum(int A[],int N)
{
//Your code here
    int sum = accumulate(A, A+N, 0);
    int Si = 0;
    for(int i = 0; i < N; i++)
    {
        Si = Si + A[i]*i;
    }
    int ans = Si;
    for(int i = 1; i < N; i++)
    {
        Si = Si + sum - N*A[N-i];
        ans = max(ans, Si);
    }
    
    return ans;

}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  
  return 0;
}
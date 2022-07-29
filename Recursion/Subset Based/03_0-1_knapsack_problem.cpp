#include<iostream>
using namespace std;

int profit(int N, int C, int *wt, int *pc)
{
    if(N == 0 || C == 0)
    return 0;

    int inc, exc;
    inc = exc = 0;

    if(wt[N-1] <= C)
    inc = pc[N-1] + profit(N-1, C-wt[N-1], wt, pc);

    exc = profit(N-1, C, wt, pc);

    return max(inc, exc);
}
int main()
{
    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};

    int N = 4;
    int C = 7;

    cout << profit(N, C, weights, prices);
    return 0;
}
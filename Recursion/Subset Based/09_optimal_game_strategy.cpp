#include<iostream>
using namespace std;


int optimalGame(int coins[], int i, int j)
{
    if(i>j)
    return 0;

    int firstPick = coins[i] + min(optimalGame(coins, i+2, j), optimalGame(coins, i+1, j-1));
    int lastPick = coins[j] + min(optimalGame(coins, i, j-2), optimalGame(coins, i+1, j-1));

    return max(firstPick, lastPick);
}
int main()
{
    int coins[30];
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    cin >> coins[i];

    cout << optimalGame(coins, 0, N-1);
    return 0;
}
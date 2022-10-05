#include<iostream>
using namespace std;

int rodCutting(int price[], int n)
{
    // base case
    if(n <= 0)
    return 0;

    // recursive case
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int currentAns = price[i] + rodCutting(price, n - cut);
        ans = max(ans, currentAns);
    }
    return ans;
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(int);

    cout << rodCutting(price, n) << endl;
    return 0;
}
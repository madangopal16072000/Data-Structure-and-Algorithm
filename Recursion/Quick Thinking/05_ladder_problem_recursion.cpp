#include<iostream>
using namespace std;

int numOfWays(int n, int k)
{
    if(n == 0)
    return 1;

    if(n<0)
    return 0;

    int ans = 0;
    for(int i=1; i<=k; i++)
    ans = ans + numOfWays(n-i, k);

    return ans;
}
int main()
{
    int n, k;
    cout << "Enter number of stairs : ";
    cin >> n;
    cout << "Enter max jumps : ";
    cin >> k;
    cout << numOfWays(n, k) << endl;
    return 0;
}
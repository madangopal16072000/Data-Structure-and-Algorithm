#include<iostream>
using namespace std;

int numOfWays(int n)
{
    if(n <= 1)
    return 1;

    return numOfWays(n-1) + (n-1)*numOfWays(n-2);
}
int main()
{
    int n;
    cout << "Enter number of Friend : ";
    cin >> n;

    cout << numOfWays(n) << endl;
    return 0;
}
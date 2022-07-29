#include<iostream>

using namespace std;
int numOfWays(int n)
{
    if(n <= 2)
    return n+1;

    return numOfWays(n-1) + numOfWays(n-2);
}
int main()
{
    int n;
    cout << "Enter length of string : ";
    cin >> n;
    cout << numOfWays(n) << endl;
    return 0;
}
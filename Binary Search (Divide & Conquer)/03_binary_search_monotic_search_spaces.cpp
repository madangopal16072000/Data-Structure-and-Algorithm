#include<iostream>
using namespace std;
float square_root(int n)
{
    int s = 0;
    int e = n;
    int mid;
    float ans = -1;
    while(s <= e )
    {
        mid = (s+e)/2;
        if(mid*mid == n)
        return mid;
        else if(mid*mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        e = mid - 1;
    }
    float inc = 0.1;
    int p = 5;
    for(int times = 1; times <= p; times++)
    {
        while(ans*ans < n)
        {
            ans = ans + inc;
        }
        // value becomes greater than n there we have to decrease by inc;
        // example n = 50
        // 1. ans = 7
        // 2. ans = 7.1 greater than 50 so subtract by inc = 0.1 and then decrement the inc by /10
        ans = ans - inc;
        inc = inc/10;
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    float result = square_root(n);
    cout << "Square Root of " << n << " : " << result << endl;
    return 0;
}
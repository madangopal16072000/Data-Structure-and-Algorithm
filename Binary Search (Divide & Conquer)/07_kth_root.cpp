#include<iostream>
#include<math.h>
using namespace std;
long long kth_root(long long n, int k)
{
    int s = 0;
    long long e = n;
    long long mid;
    long long ans = -1;
    while(s <= e)
    {
        mid = (s+e)/2;
        long long value = (long long)pow(mid, k);
        if(value == n)
        return mid;
        else if(value > n || value < 0)
        e = mid - 1;
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    long long n;
    int k;
    cin >> n >> k;
    cout << kth_root(n, k) << endl;
    return 0;
}
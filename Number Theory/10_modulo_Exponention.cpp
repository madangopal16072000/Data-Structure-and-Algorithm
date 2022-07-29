#include<iostream>
using namespace std;

int moduloExpo(int a, int b, int c)
{
    int ans = 1;
    while( b > 0)
    {
        if( (b & 1) )
        {
            ans = ans*a;
            // ans = ans%c;
        }
        a = (a*a)/c;
        b = b >> 1;
    }

    return ans;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << moduloExpo(a, b, c) << endl;
    return 0;
}
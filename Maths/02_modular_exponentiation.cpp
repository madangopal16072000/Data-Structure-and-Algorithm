#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int powr(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
        }
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return res;
}
int main()
{
    int a, b;
    a = 24;
    b = 13;

    cout << powr(a, b) << endl;
    return 0;
}
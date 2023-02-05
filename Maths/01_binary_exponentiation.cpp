#include <iostream>
using namespace std;

int powr(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a;
        }

        b = b >> 1;
        a = a * a;
    }
    return res;
}
int main()
{
    int a = 24, b = 12;
    cout << powr(a, b) << endl;
    return 0;
}
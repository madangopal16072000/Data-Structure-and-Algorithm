#include<iostream>
using namespace std;

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a%b);
}

int main()
{
    int a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    cout << GCD(a, b) << endl;
}
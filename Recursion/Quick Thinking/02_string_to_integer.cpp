#include<iostream>
#include<string>
using namespace std;

int stringToInt(string num, int length)
{
    if(length == 0)
    return 0;

    int smallAns = stringToInt(num, length-1);
    int digit = num[length - 1] - '0';
    return smallAns*10 + digit;
}
int main()
{
    string number;
    cout << "Enter string of number : ";
    cin >> number;

    cout << stringToInt(number, number.length());
    return 0;
}
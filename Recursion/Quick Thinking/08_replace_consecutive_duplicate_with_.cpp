#include<iostream>
#include<string.h>
using namespace std;

void replaceDuplicate(char str[], int length)
{
    if(length == 1)
    return;

    if(str[0] == str[1])
    {
        for(int i = length + 1; i>1; i--)
        str[i] = str[i-1];

        str[1] = '*';
    }
    return replaceDuplicate(str + 1, length - 1);
}
int main()
{
    char str[2000];
    cin >> str;

    replaceDuplicate(str, strlen(str));
    cout << str << endl;
    return 0;
}
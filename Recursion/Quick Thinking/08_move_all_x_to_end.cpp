#include<iostream>
#include<cstring>
using namespace std;

void changePos(char in[], int n)
{
    if(n == 0)
    return;

    if(in[0] == 'x')
    {
        char temp = in[0];
        int i;
        for(i = 0; i < n-1; i++)
        in[i] = in[i+1];

        in[i] = temp;
    }
    changePos(in + 1, n-1);
}
int main()
{
    char input[1002];
    cin >> input;
    changePos(input, strlen(input));
    cout << input << endl;
    return 0;
}
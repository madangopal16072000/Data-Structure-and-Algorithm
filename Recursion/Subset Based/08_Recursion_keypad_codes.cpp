#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX 1001
vector<string> keypad = {"","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

static int countString = 0;
void numOfString(char in[], char out[], int i, int j)
{
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        countString++;
        return;
    }

    int digit = in[i] - '0';
    for(int k=0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        numOfString(in, out, i+1, j+1);
    }
    return;
}
int main()
{
    char in[MAX];
    cin >> in;
    char out[MAX];
    numOfString(in, out, 0, 0);
    cout << endl << countString << endl;
    return 0;
}
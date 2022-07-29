#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> keypad = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

string searchIn[] = {
    "kartik", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void searchin(string searchIn[], char out[], int n)
{
    if(n == 0)
    return;

    if(searchIn[0].find(out) != string::npos)
    cout << searchIn[0] << endl;
    searchin(searchIn + 1, out, n-1);
}
void subString(char *in, char *out, int i, int j)
{
    if(in[i] == '\0')
    {
        // out[j] = '\0';
        // for(auto x : searchIn)
        // {
        //     if(x.find(out) != string::npos)
        //     cout << x << endl;
        // }
        // return;
        out[j] = '\0';
        searchin(searchIn, out, 11);
        return;
    }
    int digit = in[i] - '0';
    for(int k=0; keypad[digit][k] != '\0'; k++)
    {
        out[j] = keypad[digit][k];
        subString(in, out, i+1, j+1);
    }
    return;
}
int main()
{
    char in[10];
    cin >> in;
    char out[10];
    subString(in, out, 0, 0);
    return 0;
}
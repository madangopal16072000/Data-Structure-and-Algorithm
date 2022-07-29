#include<iostream>
using namespace std;

void generateSubsequences(char *in, char *out, int i, int j)
{
    // Base case
    if(in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        return;
    }

    // rec
    // include the current char

    out[j] = in[i];
    generateSubsequences(in, out, i+1, j+1);

    // exclude current char
    generateSubsequences(in, out, i+1, j);
}
int main()
{
    char input[] = "abc";
    char output[10];
    
    generateSubsequences(input, output, 0, 0);
    return 0;
}
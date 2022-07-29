#include<iostream>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void subSets(char number[], char out[], int i, int j)
{
    if(number[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = number[i] - '0';
    for(int k=0; table[digit][k] != '\0'; k++)
    {
        out[j] = table[digit][k];
        subSets(number, out, i+1, j+1);
    }
    return ;
}
int main()
{
    char number[10];
    cin >> number;
    char out[10];
    subSets(number, out, 0, 0);
    return 0;
}
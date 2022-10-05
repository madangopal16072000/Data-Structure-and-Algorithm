#include<iostream>
#include<string>
using namespace std;

int lcs(string s1, string s2, int i, int j)
{
    // base case
    if(i == s1.length() || j == s2.length())
    return 0;

    // recursive case
    if(s1[i] == s2[j])
    return 1 + lcs(s1, s2, i + 1, j + 1);

    int op1 = lcs(s1, s2, i + 1, j);
    int op2 = lcs(s1, s2, i, j+1);

    return max(op1, op2);
}

int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";

    cout << lcs(s1, s2, 0, 0) << endl;
    return 0;
}
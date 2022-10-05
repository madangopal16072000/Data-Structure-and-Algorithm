#include<iostream>
#include<string>
using namespace std;


bool isScramble(string s1, string s2)
{
    if(s1.length() <= 1)
    return false;

    
}
int main()
{
    string s1, s2;
    s1 = "great";
    s2 = "rgeat";
    cout << isScramble(s1, s2) << endl;
    return 0;
}
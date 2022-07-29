#include<iostream>
#include<set>
using namespace std;
// basicaly we will use set for stroing all permutation 
void uniquePermute(char in[], int i, set<string> &s)
{
    if(in[i] == '\0')
    {
        string temp(in);
        s.insert(temp);
        return;
    }

    for(int k=i; in[k] != '\0'; k++)
    {
        swap(in[i], in[k]);
        uniquePermute(in, i+1, s);
        swap(in[i], in[k]);
    }
    return;
}
int main()
{
    char in[10];
    cin >> in;
    set<string> s;
    uniquePermute(in, 0, s);

    for(auto x : s)
    cout << x << " ";
    return 0;
}
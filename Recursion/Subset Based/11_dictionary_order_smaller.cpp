#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


void permute(string in, string temp, int i)
{
    if(in[i] == '\0')
    {
        if(temp.compare(in) < 0)
        cout << in << endl;
        return;
    }

    for(int k = i; in[k] != '\0'; k++)
    {
        swap(in[i], in[k]);
        permute(in, temp, i+1);
        swap(in[i], in[k]);
    }
    return;
}
int main()
{
    string in;
    cin >> in;
    string temp = in;
    sort(in.begin(), in.end());
    cout << in << endl;
    permute(in, temp, 0);
    return 0;
}
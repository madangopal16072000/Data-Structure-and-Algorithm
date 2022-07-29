#include<iostream>
using namespace std;

void permute(string inp, int i, int K, string &max)
{
    if(inp[i] == '\0' || K == 0)
    {
        return;
    }
    char maxc = inp[i];
    for(int j=i+1; j<inp.length(); j++)
    {
        if(inp[j] > maxc)
        maxc = inp[j];
    }

    for(int j=i; j<inp.length(); j++)
    {
        if(inp[j] == maxc)
        {
            swap(inp[j], inp[i]);
            if(inp.compare(max) > 0)
            max = inp;

            permute(inp, i+1, K--, max);
            swap(inp[j], inp[i]);
        }
    }
}
int main()
{
    string inp;
    cin >> inp;
    int K;
    cin >> K;

    string max = inp;
    permute(inp, 0, K, max);
    cout << max << endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<numeric>
#include<set>
#include<vector>
using namespace std;

bool sumItUp(int in[], int *out, int i, int j, int N, int T, set<vector<int>> &s)
{
    if(accumulate(out, out+j, 0) == T)
    {
        s.insert({out, out+j});
        // for(int i=0; i<j; i++)
        // cout << out[i] << " ";
        // cout << endl;
        return true;
    }

    if(i == N)
    return false;

    if(accumulate(out, out+j, 0) > T)
    return false;
    out[j] = in[i];
    bool inc = sumItUp(in, out, i+1, j+1, N, T, s);
    bool exc = sumItUp(in, out, i+1, j, N, T, s);

    if(inc || exc)
    return true;

    out[j] = 0;;
    return false;
}
int main()
{
    int N;
    cin >> N;
    int in[101];
    for(int i=0; i<N; i++)
    cin >> in[i];
    int T;
    cin >> T;
    int out[101] = {0};
    set<vector<int>> s;
    sort(in, in+N);
    sumItUp(in, out, 0, 0, N, T, s);

    for(auto i = s.begin(); i!=s.end(); i++)
    {
        for(auto x : *i)
        cout << x << " ";
        cout << endl;
    }
    return 0;

}
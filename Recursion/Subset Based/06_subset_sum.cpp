#include<iostream>

using namespace std;

bool subsetSum(int in[], int N, int i, int sum)
{
    if(i == N)
    return sum == 0;

    bool inc = subsetSum(in, N, i+1, sum + in[i]);
    bool exc = subsetSum(in, N, i+1, sum);

    return inc || exc;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int in[10];
        for(int i=0; i<N; i++)
        cin >> in[i];
        int sum = 0;
        if(subsetSum(in, N, 0, sum))
        cout << "Yes" << endl;
        else
        cout << "NO" << endl;
    }
    return 0;
}
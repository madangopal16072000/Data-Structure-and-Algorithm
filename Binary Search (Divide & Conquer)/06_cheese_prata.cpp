#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int Rank[], int P, int N, int time)
{
    int prata = 0;
    for(int i=0; i<N; i++)
    {
        int sum = 0;
        int totaltime = 0;
        while(totaltime <= time)
        {
            sum = Rank[i] + sum;
            totaltime = totaltime + sum;
            prata++;
        }
        prata--;
        if(prata >= P)
        return true;
    }
    return false;
}
int min_time(int Rank[], int P, int N)
{
    int s = 0;
    sort(Rank, Rank+N);
    int e = Rank[0]*(P*(P+1))/2;
    int time;
    int ans = -1;
    while(s <= e)
    {
        time = (s+e)/2;
        
        bool result = isPossible(Rank, P, N, time);
        if(result)
        {
            ans = time;
            e = time-1;
        }
        else
        s = time+1;
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
    int P, N;
    cin >> P >> N;
    int *Rank = new int[N];
    for(int i=0; i<N; i++)
    cin >> Rank[i];

    cout << min_time(Rank, P, N) << endl;
    }

    return 0;
}
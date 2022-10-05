#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i = 0; i < n; i++)
    {
        long long d;
        cin >> d;
        pq.push(d);
    }

    long long ans = 0;
    while(pq.size() > 1)
    {
        long long temp1 = pq.top();
        pq.pop();
        long long temp2 = pq.top();
        pq.pop();

        ans = ans + temp1 + temp2;
        pq.push(temp1 + temp2);
    }
    cout << ans << endl;
}
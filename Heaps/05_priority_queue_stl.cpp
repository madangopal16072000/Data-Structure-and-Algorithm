#include<iostream>
#include<queue>

using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n;
    cout << "Enter size : ";
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int d;
        cin >> d;
        pq.push(d);
    }

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
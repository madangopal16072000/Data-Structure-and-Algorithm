#include<iostream>
#include<queue>
using namespace std;

int joinRopes(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);

    int cost = 0;
    while(pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        int newRopes = A + B;
        cost = cost + newRopes;
        pq.push(newRopes);
    }
    return cost;
}
int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = sizeof(ropes)/sizeof(int);
    cout << joinRopes(ropes, n) << endl;
    return 0;
}
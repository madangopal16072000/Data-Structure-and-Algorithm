#include<iostream>
#include<deque>

using namespace std;
#define M 10000000
int A[M];
int N;
int k;
int main()
{
    deque<int> dq;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    cin >> k;

    int i;
    for(i=0; i<k; i++)
    {
        while(!dq.empty() && A[i] > A[dq.back()])
        dq.pop_back();

        dq.push_back(i);
    }

    for(; i<N; i++)
    {
        cout << A[dq.front()] << " ";
        // remove the index which are not part of the window
        while(!dq.empty() && dq.front() <= i-k)
        dq.pop_front();

        // remove the index which are not useful
        while(!dq.empty() && A[dq.back()] < A[i])
        dq.pop_back();

        // insert the new val
        dq.push_back(i);
    }
    cout << A[dq.front()] << endl;
    return 0;
}
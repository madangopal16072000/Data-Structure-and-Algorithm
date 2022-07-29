#include<iostream>
using namespace std;


class Queue
{
    int *Q;
    int f;
    int r;
    int cs;
    int ms;

    public:

    Queue(int ds = 5)
    {
        Q = new int[ds];
        f = 0;
        r = ds-1;
        cs = 0;
        ms = 5;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    bool isFull()
    {
        return cs == ms;
    }
    void push(int data)
    {
        if(!isFull())
        {
            r = (r+1)%ms;
            Q[r] = data;
            cs++;
        }
    }

    void pop()
    {
        if(!isEmpty())
        {
            f = (f+1)%ms;
            cs--;
        }
    }

    int front()
    {
        return isEmpty() ? -1 : Q[f];
    }

    int back()
    {
        return isEmpty() ? -1 : Q[r];
    }
};

int main()
{
    Queue q;

    for(int i=1; i<=6; i++)
    {
        q.push(i);
    }

    while(!q.isEmpty())
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }

    q.pop();
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;
}
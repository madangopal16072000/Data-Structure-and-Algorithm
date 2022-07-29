#include<iostream>
#include<stack>

using namespace std;
class Queue
{
    stack<int> s1, s2;
    public:
    void push(int data)
    {
        s1.push(data);
    }

    void pop()
    {
        if(s1.empty())
        return;

        while(s1.size() > 1)
        {
            int elem = s1.top();
            s1.pop();
            s2.push(elem);
        }

        s1.pop();

        while(!s2.empty())
        {
            int elem = s2.top();
            s2.pop();
            s1.push(elem);
        }
    }

    int front()
    {
        if(s1.empty())
        return -1;

        while(s1.size() > 1)
        {
            int elem = s1.top();
            s1.pop();
            s2.push(elem);
        }
        int data = s1.top();
        while(!s2.empty())
        {
            int elem = s2.top();
            s2.pop();
            s1.push(elem);
        }
        return data;
    }

    int size()
    {
        return s1.size();
    }

    bool empty()
    {
        return size() == 0;
    }
};

int main()
{
    Queue q;

    for(int i=1; i<=5; i++)
    {
        q.push(i);
    }
    cout << q.size() << endl;
    cout << q.empty() << endl;
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << q.empty() << endl;
    cout << q.size() << endl;
}
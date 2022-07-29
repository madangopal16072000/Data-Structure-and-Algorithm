#include<iostream>
#include<stack>

using namespace std;
class Queue
{
    stack<int> s1, s2;
    public:
    void push(int data)
    {
        while(!s2.empty())
        {
            int top = s2.top();
            s2.pop();
            s1.push(top);
        }

        s1.push(data);
        while(!s1.empty())
        {
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
    }
    void pop()
    {
        s2.pop();
    }
    int top()
    {
        return s2.top();
    }
    int size()
    {
        return s2.size() + s1.size();
    }
    bool empty()
    {
        return size() == 0;
    }
};
int main()
{
    Queue q;
    for(int i=0; i<=5; i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
}
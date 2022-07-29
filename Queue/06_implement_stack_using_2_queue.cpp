#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Stack
{
    queue<T> q1, q2;
    public:
    void push(T x)
    {
        q1.push(x);
    }
    void pop()
    {
        if(q1.empty())
        return;

        while(q1.size() > 1)
        {
            T elem = q1.front();
            q2.push(elem);
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }
    T top()
    {
        if(q1.empty())
        return -1;

        while(q1.size() > 1)
        {
            T elem = q1.front();
            q2.push(elem);
            q1.pop();
        }
        T data = q1.front();
        q1.pop();
        q2.push(data);
        swap(q1, q2);

        return data;
    }

    int size()
    {
        return q1.size() + q2.size();
    }

    bool empty()
    {
        return size() == 0;
    }
};
int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;
}
#include <iostream>
#include <list>

using namespace std;

class Queue
{
private:
    int cs;
    list<int> l;

public:
    Queue()
    {
        cs = 0;
    }
    bool isEmpty()
    {
        return cs == 0;
    }

    bool isFull()
    {
        return cs == l.max_size();
    }
    void push(int data)
    {
        if (!isFull())
        {
            l.push_back(data);
            cs++;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            cs--;
            l.pop_front();
        }
    }

    int front()
    {
        return l.front();
    }
};

int main()
{
    Queue q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }

    while(!q.isEmpty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
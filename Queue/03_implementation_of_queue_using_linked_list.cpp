#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
        : data(0), next(nullptr) {}

    Node(int data)
        : data(data), next(nullptr) {}

    Node(int data, Node *next)
        : data(data), next(next) {}
};

class Queue
{
    Node *f = nullptr;
    Node *r = nullptr;
    public:
    bool isEmpty()
    {
        return f == nullptr;
    }

    bool isFull()
    {
        Node *t = new Node();
        return t == nullptr;
    }

    void push(int data)
    {
        if (!isFull())
        {
            Node *temp = new Node(data);

            if (f == nullptr)
                f = r = temp;
            else
            {
                r->next = temp;
                r = temp;
            }
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = nullptr;
            temp = f;
            f = f->next;
            delete temp;
        }
    }

    int front()
    {
        return isEmpty() ? -1 : f->data;
    }

    int back()
    {
        return isEmpty() ? -1 : r->data;
    }
};

int main()
{
    Queue q;
    for(int i=1; i<=5; i++)
    {
        q.push(i);
    }
    cout << q.isFull() << endl;
    while(!q.isEmpty())
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }

    q.pop();
    cout << q.isEmpty() << endl << q.isFull() << endl;
}
#include<iostream>
using namespace std;

class Queue
{
    private:
    int *Q;
    int size;
    int fr;
    int rear;
    public:
    Queue(int size)
    {
        Q = new int[size];
        fr = rear = 0;
    }
    bool isFull()
    {
        return (rear+1)%size == fr;
    }
    bool isEmpty()
    {
        return fr == rear;
    }
    void enqueue(int data)
    {
        if(!isFull())
        {
            rear = (rear+1)%size;
            Q[rear] = data;
        }
    }
    void dequeue()
    {
        if(!isEmpty())
        {
            fr = (fr+1)%size;
        }
    }
    int front()
    {
        if(!isEmpty())
        return Q[(fr+1)%size];
        return -1;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.front() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

    q.dequeue();
        cout << q.front() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

        q.dequeue();
        cout << q.front() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

        q.dequeue();
        cout << q.front() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

        q.dequeue();
        cout << q.front() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

            q.dequeue();
        cout << q.front() << endl;
    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

}
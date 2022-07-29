#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
        : data(data), next(nullptr) {}
};
void input(node *&head, int N, int arr[])
{
    head = new node(arr[0]);
    node *temp = head;

    for (int i = 1; i < N; i++)
    {
        node *p = new node(arr[i]);
        temp->next = p;
        temp = p;
    }
}
ostream &operator<<(ostream &os, node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return os;
}
void evenAfterOdd(node *&head)
{
    node *temp = head;
    node *lastEven = nullptr;
    while (temp)
    {
        if (temp->data % 2 == 1)
        {
            if (lastEven)
            {
                swap(temp->data, lastEven->data);
                lastEven = temp;
            }
        }
        else if(lastEven == nullptr)
        lastEven = temp;
        else if(lastEven->data != temp->data)
        lastEven = temp;

        temp = temp->next;
    }
}
int main()
{
    node* head = nullptr;
    int N;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++)
    cin >> arr[i];
    input(head, N, arr);
    cout << head << endl;
    evenAfterOdd(head);
    cout << head << endl;
    return 0;
}
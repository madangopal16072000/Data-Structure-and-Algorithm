#include <iostream>
using namespace std;
#define ASIZE 1000001
int arr1[ASIZE];
int arr2[ASIZE];
class node
{
public:
    int data;
    node *next;

    node(int data)
        : data(data), next(nullptr) {}
};
ostream &operator<<(ostream &os, node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return os;
}
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


node *merge(node *a, node *b)
{
    // Base Case
    if (a == nullptr)
        return b;

    if (b == nullptr)
        return a;

    // Recursive Case
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}
int main()
{
    int T;
    cin >> T;
    int N1, N2;
    while (T--)
    {
        cin >> N1;
        for (int i = 0; i < N1; i++)
            cin >> arr1[i];
        node *head1 = nullptr;
        input(head1, N1, arr1);

        cin >> N2;
        for (int i = 0; i < N2; i++)
            cin >> arr2[i];
        node *head2 = nullptr;
        input(head2, N2, arr2);

        node *head3 = merge(head1, head2);
        cout << head3 << endl;
    }
    return 0;
}
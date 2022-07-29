#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int data)
    : data(data), next(nullptr) {}
};
istream& operator>>(istream &is, node* &head)
{
    int n;
    cout << "Enter number of Nodes : ";
    cin >> n;
    int d;
    cout << "Enter linked list : ";
    cin >> d;

    head = new node(d);
    node *temp = head;

    for(int i=1; i<=n-1; i++)
    {
        cin >> d;
        node *p = new node(d);
        temp->next = p;
        temp = p;
    }

    return is;
}

ostream& operator<<(ostream &os, node *head)
{
    while(head)
    {
        cout << head->data << " --> ";
        head = head->next;
    }
    os << "NULL";
    return os;
}

node* reverseK(node* head, int k)
{
    if(head == nullptr)
    return nullptr;

    int jump = 1;
    node *p = nullptr;
    node *r = nullptr;
    node *q = head;
    while(q && jump <= k)
    {
        p = q->next;
        q->next = r;
        r = q;
        q = p;
        jump++;
    }
    head->next = reverseK(q, k);
    return r;

}
int main()
{
    node *head = nullptr;
    cin >> head;
    cout << head << endl;

    int k = 3;
    head = reverseK(head, k);
    cout << head;
    return 0;
}
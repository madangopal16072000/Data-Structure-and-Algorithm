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
ostream &operator<<(ostream &os, node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return os;
}

istream &operator>>(istream &is, node *&head)
{
    int d;
    cin >> d;
    if (d == -1)
        return is;
    head = new node(d);
    node *last = head;
    cin >> d;
    while (d != -1)
    {
        node *temp = new node(d);
        last->next = temp;
        last = temp;
        cin >> d;
    }
    return is;
}
int length(node *head)
{
    if(head == nullptr)
    return 0;

    return length(head->next) + 1;
}

node* insertionPoint(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    if(l1 > l2)
    {
        int jump = 1;
        while(jump <= l1-l2)
        {
            head1 = head1->next;
            jump++;
        }
    }
    else if(l2 > l1)
    {
        int jump = 1;
        while(jump <= l2 - l1)
        {
            head2 = head2->next;
            jump++;
        }
    }

    while(head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}
int main()
{
    node *head1 = nullptr;
    cin >> head1;
    cout << head1 << endl;

    node *head2 = nullptr;
    cin >> head2;
    cout << head2 << endl;

    // node *temp = head2;
    // while(temp->next)
    // temp = temp->next;

    // temp->next = head1->next->next->next->next;
    // cout << head2 << endl;

    node *point = insertionPoint(head1, head2);
    if(point)
    cout << point->data << endl;
    else
    cout << "NULL";
    return 0;
}
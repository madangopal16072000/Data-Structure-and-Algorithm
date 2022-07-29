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

bool detectCycle(node *head)
{
    node *fast = head;
    node *slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        return true;
    }
    return false;
}
node* removeCycle(node* head)
{
    node *fast = head;
    node *slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        break;
    }
    if(fast == slow)
    {
        slow = head;
        node *temp = nullptr;
        while(slow != fast)
        {
            temp = fast;
            fast = fast->next;
            slow = slow->next;
        }
        temp->next = nullptr;
        return head;
    }
    else
    return nullptr;
}
ostream& operator<<(ostream &os, node *head)
{
    while(head)
    {
        os << head->data << "->";
        head = head->next;
    }
    os << "NULL" << endl;
    return os;
}
node* input(node *head)
{
    if(head == nullptr)
    head = new node(1);
    node *temp = head;
    int length;
    cin >> length;
    while(length--)
    {
        int d;
        cin >> d;
        node *p = new node(d);
        temp->next = p;
        temp = p;
    }
    temp->next = head->next->next;
    return head;
}
int main()
{
    node *head = nullptr;
    // head = new node(1);
    // head->next = new node(2);
    // head->next->next = new node(3);

    // head->next->next->next = new node(4);
    // head->next->next->next->next = new node(5);
    // head->next->next->next->next->next = new node(6);
    // head->next->next->next->next->next->next = new node(7);
    // head->next->next->next->next->next->next->next = head->next->next;


    head = input(head);
    head = removeCycle(head);
    cout << detectCycle(head) << endl;
    
    cout << head << endl;

}
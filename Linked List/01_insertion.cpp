#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int data)
    : data(data), next(nullptr){}
};

void insertHead(node* &head, int data)
{
    if(head == nullptr)
    {
        head = new node(data);
        return;
    }

    node *c= new node(data);
    c->next = head;
    head = c;
}

void insertAtTail(node* &head, int data)
{
    if(head == nullptr)
    {
        head = new node(data);
        return;
    }

    node *tail = head;
    while(tail->next != nullptr)
    tail = tail->next;

    tail->next = new node(data);
}

int length(node *head)
{
    int count = 0;
    while(head != nullptr)
    {
        count++;
        head=head->next;
    }
    return count;
}
void insertAtMiddle(node* &head, int data, int p)
{
    if(head == nullptr)
    insertHead(head, data);

    if(p > length(head))
    insertAtTail(head, data);

    int jump = 1;
    node *c= head;
    while(jump <= p-1)
    c= c->next;

    node *n = new node(data);
    n->next = c->next;
    c->next = n;
}
void print(node *head)
{
    while(head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

bool search(node *head, int key)
{
    while(head != nullptr)
    {
        if(head->data == key)
        return true;
    }
    return false;
}

bool recursiveSearch(node *head, int key)
{
    if(head == nullptr)
    return false;

    if(head->data == key)
    return true;

    return recursiveSearch(head->next, key);
}

node* input()
{
    node *head = nullptr;
    int d;
    cin >> d;
    while(d != -1)
    {
        insertHead(head, d);
        cin >> d;
    }
    return head;
}

istream& operator>>(istream &is, node* &head)
{
    head = input();
    return is;
}
ostream& operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}
node* reverseHelper(node *p, node *q, node *r)
{
        if(q == nullptr)
    return r;

    q->next = r;
    return p ? reverseHelper(p->next, p, q) : (p, p, q);
}
node* recursiveReverse(node *head)
{
    if(head->next || head)
    return head;

    return reverseHelper(head->next, head, nullptr);
}

node* rreverse(node *p, node *q, node *r)
{
    if(q == nullptr)
    return r;

    p = q->next;
    q->next = r;
    return rreverse(p, p, q);
}

// midPoint

node* midPoint(node *head)
{
    if(head == nullptr || head->next == nullptr)
    return head;

    node *slow = head;
    node *fast = head->next;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// kth node from end

node* kthNode(node *head, int k)
{
    int jump = 1;
    node *fast = head;
    node *slow = head;
    while(jump <= k)
    {
        fast = fast->next;
        jump++;
    }

    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// merge two sorted linked list recursively

node* merge(node *a, node *b)
{
    // base case
    if(a == nullptr)
    return b;

    if(b == nullptr)
    return a;

    // rec case
    node *c= nullptr;
    if(a->data < b->data)
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
    // node *head = nullptr;

    // insertHead(head, 1);
    // insertHead(head, 5);
    // insertHead(head, 3);
    // insertHead(head, 0);


    // insertAtTail(head, 10);
    // cout << recursiveSearch(head, 5) << endl;
    // cout << recursiveSearch(head, 9) << endl;

    node *head = nullptr;
    cin >> head;
    // head = recursiveReverse(head);
    // cout << head << endl;
    // head = rreverse(nullptr, head, nullptr);
    // cout << head << endl;

    // node* mid = midPoint(head);
    // cout << mid->data << endl;

    // node *third = kthNode(head, 3);
    // cout << third->data;

    node* head2 = nullptr;
    cin >> head2;

    node* head3 = merge(head, head2);
    cout << head3 << endl;
    return 0;
}
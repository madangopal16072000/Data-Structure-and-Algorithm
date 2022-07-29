#include<iostream>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode *next;

    ListNode(int val)
    : val(val), next(nullptr) {}
};

void createList(int arr[], int n, ListNode *&head)
{
    head = new ListNode(arr[0]);
    ListNode *last = head;

    for(int i=1; i<n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        last->next = temp;
        last = temp;
    }
}

void displayList(ListNode *head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverse(ListNode *head)
{
    ListNode *p = nullptr;
    ListNode *q = head;
    ListNode *r = nullptr;

    while(q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}
int length(ListNode *head)
{
    if(!head)
    return 0;

    return length(head->next) + 1;
}
void reorderList(ListNode *head, ListNode *head2)
{
    int len = length(head);
    if(len < 3)
    return;

    ListNode *p = head;
    ListNode *q = reverse(head2);
    ListNode *s = nullptr;
    ListNode *r = nullptr;
    int i = 1;
    while(i <= len/2)
    {

        r = p->next;
        p->next = q;
        s = q->next;
        if(len%2 == 0 && i == len/2)
        q->next = nullptr;
        else
        q->next = r;
        q = s;
        p = r;

        i++;
    }
    p->next = nullptr;
}
void duplicateList(ListNode *&head2, ListNode *head)
{
    head2 = new ListNode(head->val);
    ListNode *last = head2;
    head = head->next;
    while(head)
    {
        ListNode *temp = new ListNode(head->val);
        last->next = temp;
        last = temp;
        head = head->next;
    }
}
int main()
{
    ListNode *head1 = nullptr;
    int arr[] = {1, 2, 3, 4};
    createList(arr, sizeof(arr)/sizeof(int), head1);
    ListNode *head2 = nullptr;
    // createList(arr, sizeof(arr)/sizeof(int), head2);
    duplicateList(head2, head1);
    displayList(head2);
    displayList(head1);
    reorderList(head1, head2);
    displayList(head1);

    return 0;
}
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

void reorderList(ListNode* head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *mid = slow;
    ListNode *head2 = mid->next;
    mid->next = nullptr;

    head2 = reverse(head2);
    ListNode *p2 = head2;
    ListNode *p1 = head;

    while(p2)
    {
        ListNode *next1 = p1->next;
        ListNode *next2 = p2->next;
        p1->next = p2;
        p2->next = next1;

        p1 = next1;
        p2 = next2;
    }
}

int main()
{
    ListNode *head = nullptr;
    int arr[] = {1, 2, 3, 4};
    createList(arr, sizeof(arr)/sizeof(int), head);
    displayList(head);
    reorderList(head);
    displayList(head);
}
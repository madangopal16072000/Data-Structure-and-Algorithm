#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
        : val(val), next(nullptr) {}
};

ListNode *reverse(ListNode *p, ListNode *q, ListNode *r)
{
    if (q == nullptr)
        return r;
    p = q->next;
    q->next = r;
    return reverse(p, p, q);
}
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverse(nullptr, l1, nullptr);
    l2 = reverse(nullptr, l2, nullptr);
    ListNode *l3 = new ListNode(0);
    ListNode *res = l3;
    int carry = 0;
    while (l1 && l2)
    {
        l3->val = l1->val + l2->val + carry;
        carry = 0;
        if (l3->val / 10 != 0)
        {
            l3->val = l3->val % 10;
            carry = l3->val / 10;
        }
        l1 = l1->next;
        l2 = l2->next;
        l3 = l3->next;
        l3 = new ListNode(0);
    }
    if (l1)
        l3 = l1;
    if (l2)
        l3 = l2;

    return reverse(nullptr, res, nullptr);
}

void display(ListNode *head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
int main()
{
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *l3 = addTwoNumbers(l1, l2);
    display(l3);

}
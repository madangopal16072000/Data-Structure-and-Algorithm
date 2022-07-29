/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val)
        : val(val), next(nullptr) {}
};

class Solution
{
public:
    void createList(int arr[], int n, ListNode *&head)
    {
        head = new ListNode(arr[0]);
        ListNode *last = head;

        for (int i = 1; i < n; i++)
        {
            ListNode *temp = new ListNode(arr[i]);
            last->next = temp;
            last = temp;
        }
    }
    int length(ListNode *head)
    {
        if (!head)
            return 0;

        return length(head->next) + 1;
    }
    void displayList(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *p = nullptr;
        ListNode *q = head;
        ListNode *r = nullptr;

        while (q)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = l1;
        ListNode *prev = nullptr;
        int carry = 0;
        while (l1 && l2)
        {
            l1->val = l1->val + l2->val + carry;
            carry = 0;
            if (l1->val / 10 > 0)
            {
                carry = l1->val / 10;
                l1->val = l1->val % 10;
            }
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2)
        {
            prev->next = l2;
            l1 = l2;
        }
        if (carry > 0)
        {
            while (l1)
            {
                l1->val += carry;
                carry = 0;
                if (l1->val / 10 > 0)
                {
                    carry = l1->val / 10;
                    l1->val = l1->val % 10;
                }
                prev = l1;
                l1 = l1->next;
            }
            if (carry > 0)
            {
                prev->next = new ListNode(carry);
            }
        }

        return head;
    }
};

int main()
{
    
    return 0;
}
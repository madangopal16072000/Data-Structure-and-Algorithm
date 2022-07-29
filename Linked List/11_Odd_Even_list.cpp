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
    ListNode* oddEvenList(ListNode *head)
    {
        int len = length(head);
        if (len < 3)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;

        ListNode *p = odd;
        ListNode *q = even;
        ListNode *r = even->next;

        while (r)
        {
            p->next = r;
            p = q;
            q = r;
            r = r->next;
        }
        if (len % 2 == 0)
        {
            p->next = even;
        }
        else
        {
            p->next = nullptr;
            q->next = even;
        }
        return odd;
    }
    ListNode* oddEvenFaster(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;

        ListNode *odd = head;
        ListNode *lastOdd = odd;
        ListNode *even = head->next;
        ListNode *lastEven = even;
        ListNode *curr = head->next->next;
        int pos = 1;
        while(curr)
        {
            if(pos % 2 == 1)
            {
                lastOdd->next = curr;
                lastOdd = curr;
            }
            else
            {
                lastEven->next = curr;
                lastEven = curr;
            }
            pos++;
            curr = curr->next;
        }
        lastOdd->next = even;
        lastEven->next = nullptr;
        return odd;


    }
};

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = nullptr;
    Solution s;
    s.createList(arr, n, head);
    s.displayList(head);
    head = s.oddEvenFaster(head);
    s.displayList(head);

    return 0;
}
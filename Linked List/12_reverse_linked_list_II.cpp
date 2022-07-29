#include<iostream>
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

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(!head && !head->next)
        return head;

        if(right - left == 0)
        return head;

        ListNode *temp = head;
        int pos = 1;
        while(temp)
        {
            if(pos == left)
            {
                int i = 1;
                ListNode *p = nullptr;
                ListNode *q = temp;
                ListNode *r = nullptr;
                ListNode *last = temp;
                while(i <= right - left + 1)
                {
                    r = q->next;
                    q->next = p;
                    p = q;
                    q = r;
                    i++;
                }
                last->next = r;
                if(pos == 1)
                head = p;
                else
                {
                    ListNode *t = head;
                    int j = 1;
                    while(j < left - 1)
                    {
                        t = t->next;
                        j++;
                    }
                    t->next = p;
                }
                break;
            }
            temp = temp->next;
            pos++;
        }
        return head;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    Solution s;
    ListNode *head = nullptr;
    s.createList(arr, n, head);
    int left = 2;
    int right = 4;
    head = s.reverseBetween(head, left, right);
    s.displayList(head);
    return 0;
}
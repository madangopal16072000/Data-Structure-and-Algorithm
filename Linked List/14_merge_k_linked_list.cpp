/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
#include <iostream>
#include<vector>
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
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        auto it = lists.begin();
        while(it != lists.end())
        {
            if(*it == nullptr)
            {
                it = lists.erase(it);
            }
            else
            it++;
        }
        if(lists.empty())
        return nullptr;

        if(lists.size() == 1)
        return lists[0];

        ListNode *head = nullptr;
        ListNode *last = nullptr;
        for(int i = 0; i<lists.size()-1; i++)
        {
            if(lists[i]->val < lists[i+1]->val)
            {
                head = last = lists[i];
                lists[i] = lists[i]->next;
                last->next = nullptr;
            }
            else
            {
                head = last = lists[i+1];
                lists[i+1] = lists[i+1]->next;
                last->next = nullptr;
            }
            while(lists[i] && lists[i+1])
            {
                if(lists[i]->val < lists[i+1]->val)
                {
                    last->next = lists[i];
                    last = lists[i];
                    lists[i] = lists[i]->next;
                    last->next = nullptr;
                }
                else
                {
                    last->next = lists[i+1];
                    last = lists[i+1];
                    lists[i+1] = lists[i+1]->next;
                    last->next = nullptr;
                }
            }
            if(lists[i])
            last->next = lists[i];
            else
            last->next = lists[i+1];

            lists[i+1] = head;
        }
        return head;
    }
};

int main()
{
    Solution s;
    // int arr1[] = {1, 4, 5};
    // int n1 = sizeof(arr1)/sizeof(int);
    // ListNode *l1 = nullptr;
    // s.createList(arr1, n1, l1);
    // s.displayList(l1);


    // int arr2[] = {1, 3, 4};
    // int n2 = sizeof(arr2)/sizeof(int);
    // ListNode *l2 = nullptr;
    // s.createList(arr2, n2, l2);
    // s.displayList(l2);

    // int arr3[] = {2, 6};
    // int n3 = sizeof(arr3)/sizeof(int);
    // ListNode *l3 = nullptr;
    // s.createList(arr3, n3, l3);
    // s.displayList(l3);


    // vector<ListNode*> lists;
    // lists.reserve(3);
    // lists.push_back(l1);
    // lists.push_back(l2);
    // lists.push_back(l3);
    // for(auto list : lists)
    // {
    //     s.displayList(list);
    // }

    // ListNode *l4 = nullptr;
    // l4 = s.mergeKLists(lists);
    // s.displayList(l4);
    
    // case 2
    // vector<ListNode*> lists;
    // ListNode *l5 = s.mergeKLists(lists);
    // s.displayList(l5);

    // case 3
    // vector<ListNode*> lists;
    // ListNode *l6 = nullptr;
    // ListNode *l8 = nullptr;
    // ListNode *l9 = nullptr;
    // int arr4[] = {1, 2, 3, 4};
    // s.createList(arr4, 3, l9);
    // lists.reserve(3);
    // lists.push_back(l6);
    // lists.push_back(l8);
    // lists.push_back(l9);
    // ListNode *l7 = s.mergeKLists(lists);
    // s.displayList(l7);

    // case4
    ListNode *l10 = nullptr;
    ListNode *l11 = nullptr;
    vector<ListNode*> lists;
    lists.push_back(l10);
    lists.push_back(l11);
    ListNode *l12 = s.mergeKLists(lists);
    s.displayList(l12);
    return 0;
}
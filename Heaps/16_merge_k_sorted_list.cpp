#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            ListNode *temp = lists[i];
            while (temp)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode *head = nullptr;
        if (!pq.empty())
        {
            head = new ListNode(pq.top());
            pq.pop();
        }
        while (!pq.empty())
        {
            ListNode *newPtr = new ListNode(pq.top());
            head->next = newPtr;
            head = newPtr;
            pq.pop();
        }

        return head;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}
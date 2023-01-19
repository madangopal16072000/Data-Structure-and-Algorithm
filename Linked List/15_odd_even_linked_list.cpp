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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *f, *s, *temp1, *temp2;
        f = head;
        s = head->next;
        temp1 = f;
        temp2 = s;

        while (s && s->next)
        {
            f->next = s->next;
            f = s->next;
            s->next = f->next;
            s = f->next;
        }

        f->next = temp2;
        return temp1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int d;
    cin >> d;
    ListNode *head = new ListNode(d);

    ListNode *temp = head;
    for(int i = 1; i < n; i++)
    {
        cin >> d;
        ListNode *n = new ListNode(d);
        temp->next = n;
        temp = n;
    }

    Solution sln;
    ListNode *ans = sln.oddEvenList(head);
    while(ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
public:
    Node *flatten(Node *root)
    {
        Node *ptr1 = root;
        Node *temp = root->next;
        while (temp)
        {
            Node *ptr2 = temp;
            Node *ptr = nullptr;

            if (ptr1->data <= ptr2->data)
            {
                ptr = ptr1;
                ptr1 = ptr1->bottom;
            }
            else
            {
                ptr = ptr2;
                ptr2 = ptr2->bottom;
            }
            Node *start = ptr;
            while (ptr1 && ptr2)
            {
                if (ptr1->data <= ptr2->data)
                {
                    ptr->bottom = ptr1;
                    ptr = ptr->bottom;
                    ptr1 = ptr1->bottom;
                }
                else
                {
                    ptr->bottom = ptr2;
                    ptr = ptr->bottom;
                    ptr2 = ptr2->bottom;
                }
            }

            while (ptr1)
            {
                ptr->bottom = ptr1;
                ptr1 = ptr1->bottom;
            }

            while (ptr2)
            {
                ptr->bottom = ptr2;
                ptr2 = ptr2->bottom;
            }

            ptr1 = start;
            ptr2 = nullptr;
            temp = temp->next;
        }
        return ptr1;
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
    vector<int> h;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        h.push_back(d);
        m = n + m;
    }
    vector<int> vec;
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        vec.push_back(d);
    }

    Node *head = nullptr;
    int j = 0;
    Node *hz = nullptr;
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        Node *curr = nullptr;
        Node *n = new Node(vec[j++]);
        curr = n;
        if(i == 0)
        {
            head = curr;
            hz = curr;
        }
        else
        {
            hz->next = curr;
            hz = curr;
        }
        for(; j < s + h[i]; j++)
        {
            Node *temp = new Node(vec[j]);
            curr->bottom = temp;
            curr = temp;
        }
        s = s + h[i];
    }

    Solution sln;
    Node *ans = sln.flatten(head);

    while(ans)
    {
        cout << ans->data << " ";
        ans = ans->bottom;
    }
    return 0;
}
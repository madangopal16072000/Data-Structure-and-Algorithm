#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    vector<Node *> findAnagrams(struct Node *head, string s)
    {
        // code here

        vector<Node *> ans;
        int n = s.size();
        unordered_map<char, int> mp, tmp;
        for (char ch : s)
        {
            mp[ch]++;
        }

        Node *ptr = head;

        while (ptr)
        {
            if (mp.count(ptr->data) > 0)
            {
                tmp = mp;
                Node *p = ptr;
                int cnt = 0;
                int t = 0;
                Node *it = nullptr;
                while (p && t < n)
                {
                    if (tmp.count(p->data) > 0)
                    {
                        tmp[p->data]--;

                        if (tmp[p->data] == 0)
                        {
                            tmp.erase(p->data);
                        }
                    }
                    else
                    {
                        break;
                    }
                    t++;
                    it = p;
                    p = p->next;
                }

                if (t == n)
                {
                    ans.push_back(ptr);
                    it->next = nullptr;
                    ptr = p;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            else
            {
                ptr = ptr->next;
            }
        }

        if (ans.size() == 0)
            ans.push_back(new Node(-1));

        return ans;
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
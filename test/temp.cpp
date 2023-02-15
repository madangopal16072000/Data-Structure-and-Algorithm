#include <bits/stdc++.h>
using namespace std;
#define N 1000001
class Node
{
public:
    int val;
    Node *next;
    Node(int num)
    {
        val = num;
        next = NULL;
    }
};
class Solution
{
public:
    int prime[N];
    Solution()
    {
        for (int i = 3; i < N; i = i + 2)
            prime[i] = 1;

        for (int i = 3; i < N; i = i + 2)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j < N; j = j + i)
                    prime[j] = 0;
            }
        }

        prime[0] = prime[1] = 0;
        prime[2] = 1;
    }
    int f(int num)
    {
        if (prime[num] == 1)
            return num;

        int l = num - 1;
        int r = num + 1;

        while (l > 1 && prime[l] == 0)
        {
            l--;
        }

        while (r < N - 1 && prime[r] == 0)
        {
            r++;
        }

        if (r - num >= num - l && prime[l] == 1)
            return l;
        else
            return r;
    }
    Node *primeList(Node *head)
    {

        Node *temp = head;
        while (temp)
        {
            temp->val = f(temp->val);
            temp = temp->next;
        }
        return head;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head, *tail;
        int num;
        cin >> num;
        head = tail = new Node(num);
        for (int i = 0; i < n - 1; i++)
        {
            int num;
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
            Solution ob;
            Node *temp = ob.primeList(head);
            while (temp)
            {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        return 0;
    }
}
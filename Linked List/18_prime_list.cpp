#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
#define N 1000001
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
    int n;
    cin >> n;
    int d;
    cin >> d;
    n--;

    Node *head = new Node();
    head->val = d;
    Node *temp = head;
    while (n)
    {
        Node *newNode = new Node();
        int d;
        cin >> d;
        newNode->val = d;
        temp->next = newNode;
        temp = newNode;
    }

    Solution sln;
    Node *ptr = sln.primeList(head);

    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    return 0;
}
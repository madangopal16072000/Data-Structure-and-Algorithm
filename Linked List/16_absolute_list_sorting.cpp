#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    int data;
};
class Solution{
    void reverse(Node* &head)
    {
        if(head == nullptr)
        {
            return;
        }
        Node *p = nullptr;
        Node *q = head;
        Node *r = head->next;

        while(q)
        {
            q->next = p;
            p = q;
            q = r;
            if(r)
            r = r->next;
        }
    }
public:
    Node* sortList(Node* head)
    {
        if(head == nullptr || head->next == nullptr)
        return head;

        Node *pre = head;
        Node *temp = head->next;
        Node *head2 = nullptr;
        Node *tail = nullptr;
        while(temp)
        {
            if(temp->data < 0)
            {
                if(head2 == nullptr)
                {
                    head2 = tail = temp;
                }
                else
                {
                    tail->next = temp;
                    tail = temp;
                }
                pre->next = temp->next;
            }
            else
            {
                pre = temp;
            }
            temp = temp->next;
        }

        reverse(head2);
        while(tail)
        {
            cout << tail->data << " ";
            tail = tail->next;
        }

        if(tail)
        {
            head2->next = head;
            return tail;
        }
        else
        {
            return head;
        }

    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  Node *head = new Node();
  head->data = 1;
  head->next = new Node();
  head->next->data = -2;
  head->next->next = new Node();
  head->next->next->data = -3;
  head->next->next->next = new Node();
  head->next->next->next->data = 4;
  head->next->next->next->next = new Node();
  head->next->next->next->next->data = -5;

  Solution sln;
  Node *n = sln.sortList(head);
  while(n)
  {
    cout << n->data << " ";
    n = n->next;
  }
  return 0;
}
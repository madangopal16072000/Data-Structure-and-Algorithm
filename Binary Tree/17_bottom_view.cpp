#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
        : data(data), left(nullptr), right(nullptr) {}
};
node *build()
{
    int d;
    cin >> d;
    if (d == -1)
        return nullptr;

    node *root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
        q.pop();
        cin >> d;
        if (d != -1)
        {
            f->left = new node(d);
            q.push(f->left);
        }
        cin >> d;
        if (d != -1)
        {
            f->right = new node(d);
            q.push(f->right);
        }
    }
}
void levelOrder(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == nullptr)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            q.pop();
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
}

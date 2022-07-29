#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
        : data(data), left(nullptr), right(nullptr) {}
};

Node *build()
{
    int d;
    cin >> d;
    if (d == -1)
        return nullptr;

    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cin >> d;
        if (d != -1)
        {
            f->left = new Node(d);
            q.push(f->left);
        }
        cin >> d;
        if (d != -1)
        {
            f->right = new Node(d);
            q.push(f->right);
        }
    }
    return root;
}
void levelOrder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *f = q.front();
        if (f == nullptr)
        {
            q.pop();
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            q.pop();
            cout << f->data << " ";
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
}
Node *inOrderSuccessor(Node *root, int x)
{
    // Your code
    stack<Node *> st;
    while (root || !st.empty())
    {
        if (root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            if (root->data > x)
            {
                break;
            }
            root = root->right;
        }
    }
    return root == nullptr ? nullptr : root;
}
int main()
{
    Node *root = build();
    levelOrder(root);
    cout << endl;
    Node *ans = inOrderSuccessor(root, 2);
    cout << ans->data << endl;
}
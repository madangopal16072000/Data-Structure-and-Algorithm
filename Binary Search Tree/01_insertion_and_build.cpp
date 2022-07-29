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

node *insertInBST(node *root, int d)
{
    if (root == nullptr)
        return new node(d);

    // rec case
    if (root->data >= d)
        root->left = insertInBST(root->left, d);
    else
        root->right = insertInBST(root->right, d);

    return root;
}
node *build(int arr[], int n)
{
    node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insertInBST(root, arr[i]);
    }

    return root;
}
void levelOrder(node *root)
{
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
                q.push(nullptr);
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
                q.push(f->left);

            if (f->right)
                q.push(f->right);
        }
    }
}
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        cout << p->data << " ";

        if (p->left)
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }
}
void inorder(node *root)
{
    if(root == nullptr)
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

bool search(node *root, int data)
{
    if(root == nullptr)
    return false;

    if(root->data == data)
    return true;

    // rec case
    if(data < root->data)
    return search(root->left, data);
    else
    return search(root->right, data);

}
int main()
{
    int arr[] = {8, 10, 3, 1, 6, 14, 9, 7, 13};
    int n = sizeof(arr) / sizeof(int);

    node *root = build(arr, n);
    inorder(root);
    int data;
    cin >> data;
    if(search(root, data))
    cout << "Found" << endl;
    else
    cout << "Not Found" << endl;

    return 0;
}
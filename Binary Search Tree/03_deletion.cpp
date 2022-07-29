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

node* deletion(node *root, int data)
{
    if(root == nullptr)
    return nullptr;

    if(data < root->data)
    {
        root->left = deletion(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = deletion(root->right, data);
    }
    else
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if(root->right && root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *replace = root->right;
            while(replace->left)
            replace = replace->left;

            root->data = replace->data;
            root->right = deletion(root->right, replace->data);
            return root;
        }
    }
    return root;
}
int main()
{
    int arr[] = {8, 10, 3, 1, 6, 14, 9, 7, 13};
    int n = sizeof(arr) / sizeof(int);

    node *root = build(arr, n);
    inorder(root);
    int data;
    cin >> data;
    root = deletion(root, data);
    inorder(root);

    return 0;
}
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

node* BSTFromPreorder(int pre[], int in[], int s, int e)
{
    static int i = 0;
    if(s > e)
    return nullptr;

    node *root = new node(pre[i]);
    
    int index = -1;
    for(int j = s; j<=e; j++)
    {
        if(pre[i] == in[j])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = BSTFromPreorder(pre, in, s, index-1);
    root->right = BSTFromPreorder(pre, in, index+1, e);

    return root;
}
int main()
{
    int arr[] = {8, 10, 3, 1, 6, 14, 9, 7, 13};
    int m = sizeof(arr) / sizeof(int);
    int pre[] = {5, 3, 1, 7, 6, 8};
    int n = sizeof(pre)/sizeof(int);
    int in[] = {1, 3, 5, 6, 7, 8};
    node *root = BSTFromPreorder(pre, in, 0, n-1);
    levelOrder(root);

    return 0;
}
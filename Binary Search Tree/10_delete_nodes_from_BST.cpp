#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data)
    : data(data), left(nullptr), right(nullptr) {}
};

void preorder(node *root)
{
    if(root == nullptr)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}
node* createBST(node *root, int d)
{
    if(root == nullptr)
    {
        return new node(d);
    }

    if(d < root->data)
    root->left = createBST(root->left, d);
    else
    root->right = createBST(root->right, d);
    return root;
}

node* deleteFromBST(node *root, int d)
{
    if(root == nullptr)
    return nullptr;

    if(d < root->data)
    {
        root->left = deleteFromBST(root->left, d);
    }
    else if(d > root->data)
    root->right = deleteFromBST(root->right, d);
    else
    {
        // first case
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // second case
        if(root->left && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == nullptr && root->right)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // third case
        if(root->left && root->right)
        {
            node *replace = root->right;
            while(replace->left)
            replace = replace->left;

            root->data = replace->data;
            root->right = deleteFromBST(root->right, replace->data);
            return root;
        }
    }
    return root;
}
int main()
{
    int n;
    cin >> n;
    node *root = nullptr;
    for(int i=0; i<n; i++)
    {
        int d;
        cin >> d;
        root = createBST(root, d);
    }
    preorder(root);
    cout << endl;
    int m;
    cin >> m;
    for(int i = 0; i<m; i++)
    {
        int val;
        cin >> val;
        root = deleteFromBST(root, val);
    }
    preorder(root);
    cout << endl;
}
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

node* build(node* root, int d)
{
    if(root == nullptr)
    {
        return new node(d);
    }
    if(root->data > d)
    root->left = build(root->left, d);
    else
    root->right = build(root->right, d);
    return root;
}
void inorder(node *root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}
void printInRange(node *root, int low, int high)
{
    if(root == nullptr)
    return;

    if(root->data <= high && root->data >= low)
    {
        cout << root->data << " ";
        printInRange(root->left, low, high);
        printInRange(root->right, low, high);
    }
    else if(root->data > low)
    printInRange(root->left, low, high);
    else if(root->data < high)
    printInRange(root->right, low, high);
    return;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        node *root = nullptr;
        for(int i=0; i<n; i++)
        {
            int d;
            cin >> d;
            root = build(root, d);
        }
        int low, high;
        cin >> low >> high;
        printInRange(root, low, high);
        cout << endl;
    }
    return 0;
}
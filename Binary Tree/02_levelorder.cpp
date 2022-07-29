#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    : data(data), left(nullptr), right(nullptr) {}
};

Node* buildTree()
{
    int d;
    cin >> d;
    if(d == -1)
    return nullptr;

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(Node *root)
{
    // base case
    if(!root)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int height(Node* root)
{
    if(root == nullptr)
    return 0;

    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs)+1;
}

void printKthLevel(Node *root, int k)
{
    if(!root)
    return;
    if(k == 1)
    {

    cout << root->data << " ";
    return ;
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}

void levelorder(Node *root)
{
    int h = height(root);

    for(int i=1; i<=h; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
}
int main()
{
    Node *root = buildTree();
    levelorder(root);
    return 0;
}
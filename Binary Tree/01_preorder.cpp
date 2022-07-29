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

int main()
{
    Node *root = buildTree();
    preorder(root);
    return 0;
}
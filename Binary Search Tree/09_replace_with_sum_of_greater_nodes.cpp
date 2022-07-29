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

node* createBST(int arr[], int s, int e)
{
    if(s > e)
    return nullptr;

    int mid = (s+e)/2;
    node *root = new node(arr[mid]);
    
    root->left = createBST(arr, s, mid-1);
    root->right = createBST(arr, mid+1, e);
    return root;
}

void preorder(node *root)
{
    if(!root)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void replaceSum(node *root, int &prev)
{
    if(root == nullptr)
    return;

    replaceSum(root->right, prev);
    root->data += prev;
    prev = root->data;
    replaceSum(root->left, prev);
    return;
}
int main()
{
    int n;
    cin >> n;
    int in[1000];
    for(int i=0; i<n; i++)
    {
        cin >> in[i];
    }
    node *root = createBST(in, 0, n-1);
    int prev = 0;
    replaceSum(root, prev);
    preorder(root);
    cout << endl;
    return 0;
    
}
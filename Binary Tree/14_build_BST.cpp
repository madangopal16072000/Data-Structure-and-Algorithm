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
node* buildBalanced(int arr[], int s, int e)
{
    if(s > e)
    return nullptr;

    int mid = (s+e)/2;
    node *root = new node(arr[mid]);
    root->left = buildBalanced(arr, s, mid-1);
    root->right = buildBalanced(arr, mid+1, e);
    return root;

}
void preorder(node *root)
{
    if(root == nullptr)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
        int arr[1001];
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        node *root = buildBalanced(arr, 0, n-1);
        preorder(root);
        cout << endl;
    }
}
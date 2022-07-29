#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data) 
    : data(data), left(nullptr), right(nullptr) {}
};

Node* buildTreeFromArray(int *a, int s, int e)
{
    if(s > e)
    return nullptr;

    // rec case;
    int mid = (s+e)/2;
    Node *root = new Node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid-1);
    root->right = buildTreeFromArray(a, mid+1, e);

    return root;
}
void newlineBFS(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node *f = q.front();
        if(f == nullptr)
        {
            cout << endl;
            q.pop();
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if(f->left)
            q.push(f->left);

            if(f->right)
            q.push(f->right);
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    Node *root = buildTreeFromArray(arr, 0, n-1);
    newlineBFS(root);
    return 0;

}
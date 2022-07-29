#include<iostream>
#include<queue>
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

Node* build(int arr[], int n)
{
    static int i = 0;

    if(i == n)
    return nullptr;
    if(arr[i] == -1)
    {
        i++;
        return nullptr;
    }

    Node* root = new Node(arr[i++]);
    root->left = build(arr, n);
    root->right = build(arr, n);

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

void bfs(Node *root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *f = q.front();
        cout << f->data << " ";
        q.pop();

        if(f->left)
        q.push(f->left);

        if(f->right)
        q.push(f->right);
    }
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
int replaceSum(Node *root)
{
    if(!root)
    return 0;

    if(!root->left && !root->right)
    return root->data;

    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return temp + root->data;
}
int main()
{
    int arr[] = {8, 10, 1, -1, -1, 6, 9, -1, -1, 7, -1, -1, 3, -1, 14, 13, -1, -1, -1};
    int n = sizeof(arr)/sizeof(int);
    Node *root = build(arr, n);
    newlineBFS(root);
    cout << replaceSum(root) << endl;
    newlineBFS(root);
    return 0;
}
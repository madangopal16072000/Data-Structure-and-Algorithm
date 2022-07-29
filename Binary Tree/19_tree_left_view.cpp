#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data)
    : data(data), left(nullptr), right(nullptr) {}
};

node* buildFromLO()
{
    int d;
    cin >> d;
    if(d == -1)
    return nullptr;

    node *root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node *f = q.front();
        q.pop();
        cin >> d;
        if(d != -1)
        {
            f->left = new node(d);
            q.push(f->left);
        }
        cin >> d;
        if(d != -1)
        {
            f->right = new node(d);
            q.push(f->right);
        }
    }
    return root;
}

void leftView(node *root, int &maxLevel, int level)
{
    if(root == nullptr)
    return;

    if(level > maxLevel)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    leftView(root->left, maxLevel, level+1);
    leftView(root->right, maxLevel, level+1);
    return;
}
int main()
{
    node *root = buildFromLO();
    int maxLevel = -1;
    leftView(root, maxLevel, 0);
}
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

node* build()
{
    int d;
    string lch, rch;
    cin >> d;
    node *root = new node(d);
    cin >> lch;
    if(lch == "true")
    {
        root->left = build();
        cin >> rch;
        if(rch == "true")
        root->right = build(); 
    }
    else
    {
        cin >> rch;
        if(rch == "true")
        root->right = build();
    }
    return root;
}
bool same(node *root1, node *root2)
{
    if(root1 == nullptr && root2 == nullptr)
    return true;

    if(root1 == nullptr || root2 == nullptr)
    return false;

    bool left = same(root1->left, root2->left);
    bool right = same(root1->right, root2->right);
    if(left && right)
    return true;
    else
    return false;
}

int main()
{
    node *root1 = build();
    node *root2 = build();
    cout << same(root1, root2) << endl;
    return 0;
}
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
    int d, ch;
    cin >> d;
    node *root = new node(d);
    cin >> ch;
    if(ch == 2)
    {
        root->left = build();
        root->right = build();
    }
    else if(ch == 1)
    {
        root->left = build();
    }
    return root;

}

void sumAtLevelK(node *root, int k, int &sum)
{
    if(root == nullptr)
    return;

    if(k == 0)
    {
        sum += root->data;
        return;
    }

    sumAtLevelK(root->left, k-1, sum);
    sumAtLevelK(root->right, k-1, sum);
    return;
}
int main()
{
    node *root = build();
    int k;
    cin >> k;
    int sum = 0;
    sumAtLevelK(root, k, sum);
    cout << sum << endl;
}
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Consolas, 'Courier New', monospace
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
        : data(data), left(nullptr), right(nullptr) {}
};

void printAtLevelK(node *root, int k, vector<int> &level)
{
    if(root == nullptr)
    return;

    if(k == 1)
    level.push_back(root->data);

    printAtLevelK(root->left, k-1, level);
    printAtLevelK(root->right, k-1, level);
    return;
}
int height(node *root)
{
    if(root == nullptr)
    return 0;

    return max(height(root->left), height(root->right)) + 1;
}
void levelOrder(node *root)
{
    int h = height(root);
    vector<int> ans;
    for(int i = 1; i<=h; i++)
    {
        vector<int> level;
        printAtLevelK(root, i, level);

        if(i%2 == 0)
        {
            reverse(level.begin(), level.end());
        }
        ans.insert(ans.end(), level.begin(), level.end());
        
    }

    for(auto x : ans)
    cout << x << " ";
}

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
int main()
{
    node *root = build();
    levelOrder(root);
    cout << endl;
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* build()
{
    int d;
    cin >> d;
    if(d == -1)
    return nullptr;

    TreeNode *root = new TreeNode(d);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        cin >> d;
        if(d != -1)
        {
            f->left = new TreeNode(d);
            q.push(f->left);
        }
        cin >> d;
        if(d != -1)
        {
            f->right = new TreeNode(d);
            q.push(f->right);
        }
    }
    return root;
}
void levelOrder(TreeNode *root)
{
    if(root == nullptr)
    return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        TreeNode *f = q.front();
        if(f == nullptr)
        {
            q.pop();
            cout << endl;
            if(!q.empty())
            q.push(nullptr);
        }
        else
        {
            q.pop();
            cout << f->val << " ";
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
    }
}
class Solution {
    
public:
    void helper(TreeNode *root, int &sum, int ans)
    {
        if(root == nullptr)
        {
            sum = sum + ans;
        }
        helper(root->left, sum, ans*10 + root->val);
        helper(root->right, sum, ans*10 + root->val);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, sum, 0);
        return sum/2;
    }
};
int main()
{
    TreeNode *root = build();
    levelOrder(root);
    cout << endl;
    Solution s;
    cout << s.sumNumbers(root) << endl;
}
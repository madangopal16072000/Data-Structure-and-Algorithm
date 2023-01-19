#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define M 1000000007
class Solution
{
public:
    long long dfs(TreeNode *root, long long &ans, long long sum)
    {
        if (!root)
            return 0;

        long long left = dfs(root->left, ans, sum);
        long long right = dfs(root->right, ans, sum);
        long long temp = root->val + left + right;
        ans = max(ans, temp * (sum - temp));
        return temp;
    }
    int maxProduct(TreeNode *root)
    {

        long long sum = 0;
        unordered_map<TreeNode *, TreeNode *> parent;

        queue<TreeNode *> q;
        q.push(root);
        sum = sum + root->val;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
                sum = sum + node->left->val;
            }

            if (node->right)
            {
                q.push(node->right);
                sum = sum + node->right->val;
            }
        }
        cout << sum << endl;
        long long ans = 1;

        dfs(root, ans, sum);
        ans = ans % M;
        return ans;
    }
};

TreeNode* builTree()
{
    int d;
    cin >> d;
    if(d == -1)
    return nullptr;

    TreeNode *root = new TreeNode(d);
    root->left = builTree();
    root->right = builTree();
    return root;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    
    TreeNode *root = builTree();
    Solution sln;
    cout << sln.maxProduct(root) << endl;


    return 0;
}
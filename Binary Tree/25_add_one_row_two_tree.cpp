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

class Solution
{
public:
    TreeNode *buildTree()
    {
        int d;
        cin >> d;
        if (d == -1)
            return nullptr;

        TreeNode *root = new TreeNode(d);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            cin >> d;
            if (d != -1)
            {
                node->left = new TreeNode(d);
                q.push(node->left);
            }
            cin >> d;
            if (d != -1)
            {
                node->right = new TreeNode(d);
                q.push(node->right);
            }
        }
        return root;
    }
    void printTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            cout << "null" << " ";
        }
        cout << endl;
    }
    void addNode(TreeNode *node, int val)
    {
        TreeNode *tempL, *tempR;
        tempL = node->left;
        tempR = node->right;

        node->left = new TreeNode(val, tempL, nullptr);
        node->right = new TreeNode(val, nullptr, tempR);
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        vector<TreeNode *> vec;
        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int d = q.front().second;
            q.pop();
            if (d == depth - 1)
            {
                vec.push_back(node);
            }
            if (d == depth)
            {
                break;
            }
            if (node->left)
            {
                q.push({node->left, d + 1});
            }

            if (node->right)
            {
                q.push({node->right, d + 1});
            }
        }

        for (TreeNode *node : vec)
        {
            addNode(node, val);
        }

        return root;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    Solution sln;
    TreeNode *root = sln.buildTree();
    sln.printTree(root);
    sln.addOneRow(root, 1, 2);
    sln.printTree(root);
    return 0;
}
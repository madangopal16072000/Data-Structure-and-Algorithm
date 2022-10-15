#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void f(TreeNode *root, int k, vector<int> &row)
    {
        if(root == nullptr)
            return;
        
        f(root->left, k, row);
        row.push_back(root->val);
        f(root->right, k, row);
        return;
    }
    bool g(int i, int k, vector<int> nums, vector<vector<int>> dp)
    {
        if(k == 0)
            return true;
        
        if(i < 0 || k < 0)
            return false;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        return dp[i][k] = g(i-1, k, nums, dp) || g(i-1, k-nums[i], nums, dp);
    }
    bool g1(vector<int> row, int t)
    {
        int n = row.size();

        vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(t+1, vector<bool>(2, false)));
        for(int i = 0; i <= n; i++)
        {
            dp[i][0][0] = true;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= t; j++)
            {
                for(int k = 1; k <= 2; k++)
                {
                    dp[i][j][k] = dp[i-1][j-row[i-1]][k-1] || dp[i-1][j][k];
                }
            }
        }
        return dp[n][t][2];
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> row;
        f(root, k, row);

        return g1(row, k);
        
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<int> row;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        row.push_back(d);
    }
    Solution sln;
    int k = -1;
    cout << sln.g1(row, k);
    return 0;
}
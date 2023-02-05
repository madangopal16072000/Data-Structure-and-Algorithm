#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    unordered_map<char, Node *> children;
    int cnt;

    Node(char data)
    {
        this->data = data;
        cnt = 0;
    }
};
class Solution
{
    Node *root;

public:
    Solution()
    {
        root = new Node('\0');
    }

    void insert(string &word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->cnt++;
    }
    void dfs(Node *temp, int i, int j, vector<string> &ans, string s, vector<vector<char>> &matrix, int R, int C, vector<vector<bool>> &vis)
    {
        if (temp->children.count(matrix[i][j]) == 0)
            return;
        vis[i][j] = true;
        temp = temp->children[matrix[i][j]];
        s = s + matrix[i][j];

        if (temp->cnt > 0)
        {
            ans.push_back(s);
            temp->cnt--;
        }

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int k = 0; k < 8; k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];

            if (r < R && r >= 0 && c < C && c >= 0 && vis[r][c] == false)
            {
                dfs(temp, r, c, ans, s, matrix, R, C, vis);
            }
        }
        vis[i][j] = false;
    }
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
    {
        // Code here

        for (string &word : dictionary)
        {
            insert(word);
        }

        int R = board.size();
        int C = board[0].size();
        vector<string> ans;
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                Node *temp = root;

                dfs(temp, i, j, ans, "", board, R, C, vis);
            }
        }

        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> dictionary;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        dictionary.push_back(s);
    }

    int R, C;
    cin >> R >> C;
    vector<vector<char>> board;
    for (int i = 0; i < R; i++)
    {
        vector<char> row;
        for (int j = 0; j < C; j++)
        {
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        board.push_back(row);
    }

    Solution sln;
    vector<string> ans = sln.wordBoggle(board, dictionary);
    for (string s : ans)
        cout << s << " ";
    return 0;
}
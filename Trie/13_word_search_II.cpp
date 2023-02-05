#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *children[26] = {nullptr};
    bool terminal;

    Node(char data)
    {
        this->data = data;
        terminal = false;
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
            if (temp->children[ch - 'a'] == nullptr)
            {
                Node *newNode = new Node(ch);
                temp->children[ch - 'a'] = newNode;
            }
            temp = temp->children[ch - 'a'];
        }
        temp->terminal = true;
    }

    void search(int i, int j, Node *temp, vector<vector<char>> &board, vector<string> &ans, string s, vector<vector<bool>> vis)
    {
        if (temp->children[board[i][j] - 'a'] == nullptr)
            return;

        int m = board.size();
        int n = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        vis[i][j] = true;
        temp = temp->children[board[i][j] - 'a'];
        s = s + temp->data;
        if (temp->terminal)
        {
            ans.push_back(s);
            temp->terminal = false;
        }
        for (int k = 0; k < 4; k++)
        {
            int r = drow[k] + i;
            int c = dcol[k] + j;

            if (r >= 0 && r < m && c >= 0 && c < n && vis[r][c] == false)
            {
                char ch = board[r][c];

                if (temp->children[ch - 'a'] != nullptr)
                {
                    search(r, c, temp, board, ans, s, vis);
                }
            }
        }
        return;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        for (string &word : words)
        {
            insert(word);
        }

        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Node *temp = root;
                string s = "";
                if (temp->children[board[i][j] - 'a'] != nullptr)
                {
                    search(i, j, temp, board, ans, s, vis);
                }
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
    int m;
    int n;
    cin >> m >> n;
    vector<vector<char>> board;
    for (int i = 0; i < m; i++)
    {
        vector<char> row;
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        board.push_back(row);
    }

    int t;
    cin >> t;
    vector<string> words;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
    }

    Solution sln;
    vector<string> ans = sln.findWords(board, words);
    for (string str : ans)
        cout << str << " ";

    return 0;
}
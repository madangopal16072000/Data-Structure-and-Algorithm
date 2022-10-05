#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char data)
        : data(data), terminal(false) {}
};
class Solution
{
    Node *root;
    int cnt;

public:
    Solution()
    {
        root = new Node('\0');
        cnt = 0;
    }

    bool helper(string s, int i)
    {
        Node *temp = root;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(temp->terminal && i == s.length() - 1)
            {
                temp = root;
            }
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
            {
                if (temp->terminal && root->children[ch])
                {
                    temp = root->children[ch];
                }
                else
                    return false;
            }
        }
        return temp->terminal;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Node *temp = root;
        for (int i = 0; i < wordDict.size(); i++)
        {
            temp = root;
            for (int j = 0; j < wordDict[i].length(); j++)
            {
                char ch = wordDict[i][j];
                if (temp->children.count(ch))
                {
                    temp = temp->children[ch];
                }
                else
                {
                    Node *n = new Node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            temp->terminal = true;
        }

        return helper(s, 0);
    }
};
int main()
{
    Solution t;

    string s = "aaaaaaa";
    vector<string> wordDict {"aaaa","aaa"};

    cout << t.wordBreak(s, wordDict) << endl;
    return 0;
}
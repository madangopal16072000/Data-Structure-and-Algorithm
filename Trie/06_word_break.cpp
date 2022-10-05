#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char data)
    : data(data), terminal(false) {}
};

class Trie
{
    Node *root;
    int cnt;

    public:
    Trie()
    {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(string s);
    bool wordBreak(string s, vector<string> &wordDict);
    bool helper(string s, int i);

};

void Trie::insert(string s)
{
    Node *temp = root;
    for(int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if(temp->children.count(ch))
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
// bool Trie::find(string s)
// {
//     Node *temp = root;
//     for(int i = 0; s[i] != '\0'; i++)
//     {
//         char ch = s[i];
//         if(temp->children.count(ch) == 0)
//         return false;
//         else
//         temp = temp->children[ch];
//     }
//     return temp->terminal;
// }

bool Trie::helper(string s, int i)
{
    Node *temp = root;
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if(temp->children.count(ch))
        {
            temp = temp->children[ch];
        }
        else
        {
            if(temp->terminal && root->children[ch])
            {
                temp = root->children[ch];
            }
            else
            return false;
        }
    }
    return temp->terminal;
}
bool Trie::wordBreak(string s, vector<string> &wordDict)
{
    Node *temp = root;
    for(int i = 0; i < wordDict.size(); i++)
    {
        temp = root;
        for(int j = 0; j < wordDict[i].length(); j++)
        {
            char ch = wordDict[i][j];
            if(temp->children.count(ch))
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
// bool helper(string s, Trie &t, int i)
// {

// }
// bool wordBreak(string s, vector<string> &wordDict)
// {
//     Trie t;
//     for(int i = 0; i < wordDict.size(); i++)
//     {
//         t.insert(wordDict[i]);
//     }

//     return helper(s, t, 0);
// }
int main()
{
    Trie t;

    string s = "applepenapple";
    vector<string> wordDict {"apple","pen"};

    cout << t.wordBreak(s, wordDict) << endl;
    return 0;
}



#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char data)
    {
        this->data = data;
        terminal = false;
    }
};
class MagicDictionary
{
    Node *root;

public:
    MagicDictionary()
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
        temp->terminal = true;
    }
    void buildDict(vector<string> dictionary)
    {

        for (string &s : dictionary)
        {
            insert(s);
        }
    }
    bool dfs(Node *temp, string &searchWord, int idx, bool isChanged, int n)
    {
        if (!temp)
            return false;

        if (idx == n)
            return temp->terminal;

        if (temp->children.count(searchWord[idx]) == 0)
        {
            if (isChanged == false)
            {
                for (auto p : temp->children)
                {
                    if (dfs(p.second, searchWord, idx + 1, true, n))
                        return true;
                }
                return false;
            }
            else
            {
                return false;
            }
        }

        return dfs(temp->children[searchWord[idx]], searchWord, idx + 1, isChanged, n);
    }
    bool search(string searchWord)
    {

        Node *temp = root;
        bool isChanged = false;

        if (dfs(temp, searchWord, 0, isChanged, searchWord.size()) && isChanged == true)
            return true;

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    MagicDictionary *obj = new MagicDictionary();
    vector<string> dictionary = {"hello", "leetcode"};
    obj->buildDict(dictionary);
    cout << obj->search("hhllo") << endl;
    return 0;
}
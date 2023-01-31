#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char ch)
    {
        data = ch;
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
            if (temp->children.count(ch) == 0)
            {
                Node *newNode = new Node(ch);
                temp->children[ch] = newNode;
            }
            temp = temp->children[ch];
        }
        temp->terminal = true;
    }
    string f(string &word)
    {
        Node *temp = root;
        string out = "";
        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                return word;
            }
            else
            {
                temp = temp->children[ch];
                out = out + temp->data;
                if (temp->terminal)
                {
                    return out;
                }
            }
        }
        return word;
    }
    string replaceWords(vector<string> &dictionary, string sentence)
    {

        for (string word : dictionary)
        {
            insert(word);
        }
        sentence = sentence + " ";
        int n = sentence.size();
        string ans = "";
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            char ch = sentence[i];

            if (ch == ' ')
            {

                temp = f(temp);

                if (ans.size() == 0)
                {
                    ans = temp;
                }
                else
                {
                    ans = ans + " " + temp;
                }
                temp = "";
            }
            else
            {
                temp = temp + ch;
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
    vector<string> dictionary;
    string sentence = "the cattle was rattled by the battery";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        dictionary.push_back(temp);
    }
    Solution sln;
    cout << sln.replaceWords(dictionary, sentence) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    unordered_map<char, Node *> children;
    int cw;
    int cp;

    Node(char ch)
    {
        data = ch;
        cw = 0;
        cp = 0;
    }
};
class Trie
{
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
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
            temp->cp++;
        }
        temp->cw++;
    }

    bool find(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) > 0)
            {
                temp = temp->children[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->cw > 0;
    }

    int countWordsEqualTo(string &word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) > 0)
            {
                temp = temp->children[ch];
            }
            else
            {
                return 0;
            }
        }
        return temp->cw;
    }

    int countWordsStartingWith(string &word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) > 0)
            {
                temp = temp->children[ch];
            }
            else
            {
                return 0;
            }
        }
        return temp->cp;
    }

    void erase(string &word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) > 0)
            {
                temp = temp->children[ch];
                temp->cp--;
            }
            else
                return;
        }
        temp->cw--;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}
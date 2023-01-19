#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left;
    int k;
    int v;
    Node *right;
};
class LRUCache
{
    Node *head, *tail;
    unordered_map<int, Node *> mp;
    int size;

public:
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->left = tail->right = nullptr;
        head->right = tail;
        tail->left = head;
    }
    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *temp = mp[key];
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            temp->left = temp->right = nullptr;

            temp->right = head->right;
            head->right->left = temp;
            temp->left = head;
            head->right = temp;
            temp->v = value;
            return;
        }
        else if (mp.size() == size)
        {
            Node *temp = tail->left;
            temp->left->right = temp->right;
            tail->left = temp->left;

            temp->left = temp->right = nullptr;
            int k = temp->k;
            delete temp;
            mp.erase(k);
        }
        Node *newNode = new Node();
        newNode->right = head->right;
        head->right->left = newNode;
        newNode->left = head;
        head->right = newNode;
        newNode->v = value;
        newNode->k = key;
        mp[key] = newNode;
    }
    int get(int key)
    {
        if(mp.count(key) > 0)
        {
            Node *temp = mp[key];
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            temp->left = temp->right = nullptr;

            temp->right = head->right;
            head->right->left = temp;
            temp->left = head;
            head->right = temp;

            return temp->v;
        }
        else
        {
            return -1;
        }
    }
};
class LRUCache1
{
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int size;
    public:
    LRUCache1(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if(mp.count(key) > 0)
        {
            list<pair<int, int>>::iterator it = mp[key];
            auto p = *it;
            l.erase(it);
            it = l.begin();
            mp[key] = l.insert(it, {key, p.second});
            return p.second;
        }
        else
        {
            return -1;
        }

    }

    void put(int key, int value)
    {
        if(mp.count(key) > 0)
        {
            l.erase(mp[key]);
        }
        else if(mp.size() == size)
        {
            auto it = l.end();
            it--;
            l.erase(it);
            auto p = *it;
            mp.erase(p.first);
        }
        auto it = l.begin();
        mp[key] = l.insert(it, {key, value});
        
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("./input.txt", "r", stdin);
//     freopen("./output.txt", "w", stdout);
// #endif
    LRUCache1 *obj = new LRUCache1(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}
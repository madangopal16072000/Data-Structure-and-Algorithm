#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<vector>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    : data(data), left(nullptr), right(nullptr) {}
};

node* build()
{
    int d;
    cin >> d;
    if(d == -1)
    return nullptr;

    node *root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *f = q.front();
        q.pop();
        cin >> d;
        if(d != -1)
        {
            f->left = new node(d);
            q.push(f->left);
        }
        cin >> d;
        if(d != -1)
        {
            f->right = new node(d);
            q.push(f->right);
        }
    }
    return root;
}
void levelOrder(node *root)
{
    if(root == nullptr)
    return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        node *f = q.front();
        if(f == nullptr)
        {
            q.pop();
            cout << endl;
            if(!q.empty())
            q.push(nullptr);
        }
        else
        {
            q.pop();
            cout << f->data << " ";
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
    }
}
vector<vector<int>> vertical(node *root)
{
    map<int, map<int, multiset<int>>> m;
    queue<tuple<node*, int, int>> q;

    q.push(make_tuple(root, 0, 0));
    while(!q.empty())
    {
        auto t = q.front();
        node *f = get<0>(t);
        int v = get<1>(t);
        int l = get<2>(t);
        m[v][l].insert(f->data);
        q.pop();
        if(f->left)
        {
            q.push(make_tuple(f->left, v-1, l+1));
        }
        if(f->right)
        {
            q.push(make_tuple(f->right, v+1, l+1));
        }
    }
    vector<vector<int>> vec;
    for(auto p : m)
    {
        vector<int> col;
        for(auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        vec.push_back(col);
    }
    return vec;
}
int main()
{
    node *root = build();
    levelOrder(root);
    cout << "Vertical Order : " << endl;
    vector<vector<int>> vec = vertical(root);
    for(auto p : vec)
    {
        for(auto q : p)
        {
            cout << q << " ";
        }
        cout << endl;
    }
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    : data(data), left(nullptr), right(nullptr) {}
};

Node* createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    if(s > e)
    return nullptr;

    // rec case;
    Node *root = new Node(pre[i]);

    int index = -1;
    for(int j = s; j <= e; j++)
    {
        if(pre[i] == in[j])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index-1);
    root->right = createTreeFromTrav(in, pre, index+1, e);
    return root;
}
void newlineBFS(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node *f = q.front();
        if(f == nullptr)
        {
            cout << endl;
            q.pop();
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if(f->left)
            q.push(f->left);

            if(f->right)
            q.push(f->right);
        }
    }
}

int main()
{
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3,4, 8, 5, 6, 7};
    int n = sizeof(in)/sizeof(int);
    
    Node *root = createTreeFromTrav(in, pre, 0, n-1);
    newlineBFS(root);
}
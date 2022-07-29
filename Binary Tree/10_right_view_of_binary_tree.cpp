#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data) 
    : data(data), left(nullptr), right(nullptr) {}
};

node* createTree(int arr[], int n)
{
    queue<node*> q;
    node *root = new node(arr[0]);
    q.push(root);

    int i = 1;
    while(!q.empty() && i<n)
    {
        node *p = q.front();
        q.pop();

        if(arr[i] != -1)
        {
            p->left = new node(arr[i]);
            q.push(p->left);
        }
        i++;

        if(arr[i] != -1)
        {
            p->right = new node(arr[i]);
            q.push(p->right);
        }
        i++;
    }
    
    return root;
}

void printRightView(node *root, int level, int &maxlevel)
{
    if(!root)
    return ;

    if(maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }

    // right
    printRightView(root->right, level+1, maxlevel);
    printRightView(root->left, level+1, maxlevel);
}
void newlineBFS(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        node *f = q.front();
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
    int arr[] = {1, 2, 3, 4, 5, -1, -1, 6, 7, 8, 9,-1,  -1, 10, 11, -1, -1, -1, -1};
    int n = sizeof(arr)/sizeof(int);

    node *root = createTree(arr, n);
    cout << "Displaying Tree : " << endl;
    newlineBFS(root);
    cout << "Printing Right View : " << endl;
    int maxlevel = -1;
    printRightView(root, 0, maxlevel);

    return 0;
}
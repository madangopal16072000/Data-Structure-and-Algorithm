#include <iostream>
#include <vector>

using namespace std;
struct node
{
    node *left;
    node *right;
};

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        node *temp = root;
        for (int i = 4; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if(temp->right == nullptr)
                temp->right = new node();

                temp = temp->right;
            }
        }
    }

    int maxXORHelper(int val)
    {
        int currentAns = 0;
        node *temp = root;
        for(int i = 4; i>=0; i--)
        {
            int bit = (val >> i) & 1;
            if(bit == 0)
            {
                if(temp->right)
                {
                    currentAns += (1 << i);
                    temp = temp->right;
                }
                else
                temp = temp->left;
            }
            else
            {
                if(temp->left)
                {
                    currentAns += (1 << i);
                    temp = temp->left;
                }
                else
                temp = temp->right;
            }
        }
        return currentAns;
    }

    int maxXOR(vector<int> input)
    {
        int maxXR = 0;
        for(int i = 0; i<input.size(); i++)
        {
            int val = input[i];
            insert(val);
            int currentAns = maxXORHelper(val);
            cout << currentAns << " ";
            maxXR = max(maxXR, currentAns);
        }
        return maxXR;
    }
}; 
int main()
{
    vector<int> input{3, 10, 5, 25, 2, 8};
    Trie t;
    cout << endl <<  t.maxXOR(input) << endl;
    return 0;
}
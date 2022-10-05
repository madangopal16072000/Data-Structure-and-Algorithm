#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void solve(string &res, int i, int k)
    {
        if(res[i] == 'L' && res[k] == 'L')
        {
            for(int j = i+1; j < k; j++)
            {
                res[j] = 'L';
            }
        }
        else if(res[i] == 'R' && res[k] == 'R')
        {
            for(int j = i+1; j < k; j++)
            {
                res[j] = 'R';
            }
        }
        else if(res[i] == 'R' && res[k] == 'L')
        {
            int diff = k - i;
            if(diff % 2 == 0)
            {
                int mid = (k+i)/2;
                for(int j = i+1; j < mid; j++)
                {
                    res[j] = 'R';
                }
                for(int j = mid+1; j < k; j++)
                {
                    res[j] = 'L';
                }
            }
            else
            {
                int mid = (k+i)/2;
                for(int j = i+1; j <= mid; j++)
                {
                    res[j] = 'R';
                }
                for(int j = mid+1; j < k; j++)
                {
                    res[j] = 'L';
                }
            }
        }
    }
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string ans = "";
        ans += "L";
        ans += dominoes;
        ans += "R";
        int i = 0;
        int k = 1;
        while(k < ans.length())
        {
            while(ans[k] == '.')
            k++;

            if(k-i > 1)
            solve(ans, i, k);

            i = k;
            k++;
        }

        string res = "";
        for(int j = 1; j < ans.length()-1; j++)
        {
            res.push_back(ans[j]);
        }
        return res;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("./input.txt", "r", stdin);
//     freopen("./output.txt", "w", stdout);
// #endif
    string dominoes;
    cin >> dominoes;
    Solution sln;
    cout << sln.pushDominoes(dominoes) << endl;
    return 0;
}
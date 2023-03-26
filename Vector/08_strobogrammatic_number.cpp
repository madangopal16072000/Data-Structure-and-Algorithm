#include <bits/stdc++.h>
using namespace std;
vector<string> findStrobogrammatic(int n)
{
    // Write your code here.

    unordered_map<char, bool> mp;
    mp['0'] = true;
    mp['1'] = true;
    mp['8'] = true;

    int s = 1;
    int e = 9;
    int m = n;
    while (m > 1)
    {
        s = s * 10;
        e = s * 10 + 9;
        m--;
    }
    vector<string> ans;
    for (int k = s; k <= e; k++)
    {
        string nums = to_string(k);

        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (mp.count(nums[i]) && mp.count(nums[j]) && nums[i] == nums[j])
            {
                i++;
                j--;
            }
            else if ((nums[i] == '9' && nums[j] == '6') || (nums[i] == '6' && nums[j] == '9'))
            {
                i++;
                j--;
            }
            else
                break;
        }
        if (j < i)
        {
            ans.push_back(nums);
        }
    }

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<string> ans = findStrobogrammatic(n);
    for (string s : ans)
        cout << s << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {

        vector<string> vec;
        for (int x : nums)
        {
            string temp = to_string(x);
            vec.push_back(temp);
        }

        sort(vec.begin(), vec.end());
        for (string s : vec)
            cout << s << " ";

        return "";
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    Solution sln;
    cout << sln.largestNumber(nums) << endl;
    return 0;
}
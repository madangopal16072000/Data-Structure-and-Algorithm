#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverse(vector<int> &arr, int s, int e)
    {
        while (s < e)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int maxIdx = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[maxIdx] < arr[j])
                {
                    maxIdx = j;
                }
            }

            if (maxIdx == i)
                continue;

            if (maxIdx != 0)
            {
                reverse(arr, 0, maxIdx);
                ans.push_back(maxIdx + 1);
            }

            reverse(arr, 0, i);
            ans.push_back(i + 1);
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

    return 0;
}
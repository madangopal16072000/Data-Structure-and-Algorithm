#include <bits/stdc++.h>
using namespace std;

bool compare(string &s1, string &s2)
{
    return s1.length() < s2.length();
}
class Solution
{
public:
    bool canInsert(string pred, string succ)
    {
        int cnt = 0;
        for (int i = 0; succ[i] != '\0'; i++)
        {
            if (pred[i] != succ[i] && cnt != 1)
            {
                pred.insert(i, 1, succ[i]);
                cnt++;
            }
        }
        return succ.compare(pred) == 0 ? true : false;
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxSize = 1;
        int lastIdx = 0;
        sort(words.begin(), words.end(), compare);
        for (string s : words)
            cout << s << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (words[j].length() < words[i].length() && canInsert(words[j], words[i]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (maxSize < dp[i])
            {
                maxSize = dp[i];
                lastIdx = i;
            }
        }

        return maxSize;
    }
};

int main()
{
    // int n;
    // cin >> n;
    vector<string> words{{"a","b","ba","bca","bda","bdca"}};
    // for(int i = 0; i < n; i++)
    // {
    //     string word;
    //     cin >> word;
    //     words.push_back(word);
    // }

    Solution s;
    cout << s.longestStrChain(words) << endl;
    return 0;
}
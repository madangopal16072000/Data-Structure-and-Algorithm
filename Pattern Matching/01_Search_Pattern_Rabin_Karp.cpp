#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long MOD;
    long long p;
    long long hashing(string pat)
    {
        long long p_power = 1;
        long long hash = 0;

        int n = pat.size();
        for (int i = 0; i < n; i++)
        {
            hash = hash + ((pat[i] - 'a' + 1) * p_power) % MOD;
            hash = hash % MOD;
            p_power = p_power * p;
        }
        return hash;
    }
    // long long powr(int a, int b)
    // {
    //     long long res = 1;
    //     while (b)
    //     {
    //         if (b & 1)
    //         {
    //             res = (res * a) % MOD;
    //         }
    //         b = b >> 1;
    //         a = (a * a) % MOD;
    //     }
    //     return res;
    // }
    // long long inv(int a)
    // {
    //     return powr(a, MOD - 2);
    // }
    int powr(int a, int b)
    {
        // (a^b)%MOD
        int res = 1;
        while (b)
        {
            if (b & 1)
                res *= a;
            b /= 2;
            a *= a;

            a %= MOD;
            res %= MOD;
        }
        return res;
    }

    int inv(int x)
    {
        return powr(x, MOD - 2);
    }

public:
    Solution()
    {
        MOD = 8329;
        p = 31;
    }
    vector<int> search(string pat, string txt)
    {
        // code here.
        int m = pat.size();
        int n = txt.size();

        long long pat_hash = hashing(pat);
        long long txt_hash = 0;

        int i = 0;
        int j = 0;
        long long p_power = 1;
        vector<int> ans;
        while (j < n)
        {
            txt_hash = (txt_hash + ((txt[j] - 'a' + 1) * p_power) % MOD) % MOD;
            if (j - i + 1 < m)
            {
                j++;
                p_power = (p_power * p) % MOD;
                continue;
            }
            else if (pat_hash == txt_hash)
            {
                ans.push_back(i + 1);
            }

            txt_hash = (txt_hash - (txt[i] - 'a' + 1) + MOD) % MOD;

            txt_hash = (txt_hash * inv(p)) % MOD;
            i++;
            j++;
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
    string pat;
    string txt;
    cin >> txt >> pat;
    Solution sln;
    vector<int> ans = sln.search(pat, txt);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
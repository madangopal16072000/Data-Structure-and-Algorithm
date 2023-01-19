#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	int search(string pat, string txt) {
	    // code here

        unordered_map<char, int> mp;
        for(char ch : pat)
        {
            mp[ch]++;
        }
        int k = pat.size();
        int cnt = mp.size();
        int n = txt.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j < n)
        {
            char ch = txt[j];
            if(mp.count(ch))
            {
                mp[ch]--;

                if(mp[ch] == 0)
                {
                    cnt--;
                }
            }

            if(j-i+1 < k)
            j++;
            else
            {
                if(cnt == 0)
                {
                    ans++;
                }

                if(mp.count(txt[i]))
                {
                    mp[txt[i]]++;

                    if(mp[txt[i]] == 1)
                    {
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }

        return ans;
	}

};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  string txt = "aabaabaa";
  string pat = "aaba";

  Solution sln;
  cout << sln.search(pat, txt) << endl;
  return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> m;
    int start = 0;
    int cnt = 0;
    int maxLength = INT_MIN;
    int startIdx = -1;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (m[ch])
        {
            if (cnt > maxLength)
            {
                startIdx = start;
                maxLength = cnt;
            }
            while (m[ch] != 0)
            {
                char temp = s[start];
                start++;
                m[temp]--;
                cnt--;
            }
        }
        cnt++;
        m[ch]++;
    }
    // cout << s.substr(startIdx, maxLength) << endl;
    return max(maxLength, cnt);
}
int main()
{
    string s = "abcabcbb";
    // cout << "Enter string : ";
    // cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
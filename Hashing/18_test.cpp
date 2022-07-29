#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;


string minWindow(string s, string pat)
{
    int LS = s.length();
    int LP = pat.length();

    if(LP > LS)
    return "";

    unordered_map<char, int> HP;
    for(int i = 0; pat[i] != '\0'; i++)
    HP[pat[i]]++;


    unordered_map<char, int> HS;
    int start = 0, cnt = 0;
    int minLen = INT_MAX, startIdx = -1;
    for(int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        HS[ch]++;

        if(HP[ch] != 0 && HS[ch] <= HP[ch])
        cnt++;

        if(cnt == LP)
        {
            char temp = s[start];
            // start shrinking the window
            while(HP[temp] == 0 || HS[temp] > HP[temp])
            {
                HS[temp]--;
                start++;
                temp = s[start];
            }

            int windowLen = i - start + 1;
            if(windowLen < minLen)
            {
                minLen = windowLen;
                startIdx = start;
            }
        }
    }
    if(startIdx == -1)
    {
        return "";
    }
    else
    {
        return s.substr(startIdx, minLen);
    }
}
int main()
{
    string s, pat;
    getline(cin, s);
    getline(cin, pat);
    // string s = "madan gopal srivastava";
    // string pat = "gos";

    string out = minWindow(s, pat);
    cout << out << endl;
    return 0;
}
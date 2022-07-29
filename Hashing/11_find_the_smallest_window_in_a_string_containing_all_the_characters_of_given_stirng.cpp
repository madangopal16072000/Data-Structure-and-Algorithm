#include<iostream>
#include<string>
using namespace std;


string findWindow(string s, string pat)
{
    int SL = s.length();
    int PL = pat.length();

    // corner case
    if(PL > SL)
    return "NONE";

    // freq maps;
    int FS[256] = {0};
    int FP[256] = {0};

    for(int i=0; i<PL; i++)
    FP[pat[i]]++;

    // sliding window (Expansion and contraction + update min length of the window)
    int start = 0, minLen = INT_MAX, startIdx = -1;
    int cnt = 0;

    for(int i=0; i<SL; i++)
    {
        FS[s[i]]++;

        // mainting the count of characters of matched
        if(FP[s[i]] != 0 && FS[s[i]] <= FP[s[i]])
        cnt++;

        // if all the characters matched
        if(cnt == PL)
        {
            // start shrinking the window
            char temp = s[start];

            // loop to remove all unwanted characters 
            while(FP[temp] == 0 || FS[temp] > FP[temp])
            {
                FS[temp]--;
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
    return "NONE";

    string ans = s.substr(startIdx, minLen);
    return ans;

}
int main()
{
    string s = "helelomeeo world";
    string pat = "eelo";

    cout << findWindow(s, pat) << endl;
    return 0;
}
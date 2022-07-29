#include <iostream>
#include <unordered_set>
using namespace std;

int findLargestSubseq(int arr[], int n)
{
    unordered_set<int> s;
    for(int i=0; i<n; i++)
    s.insert(arr[i]);

    // int maxStreak = 0;
    // for(int i = 0; i < n; i++)
    // {
    //     if(s.find(arr[i] - 1) == s.end())
    //     {
    //         int nextNo = arr[i] + 1;
    //         int streakLen = 1;
    //         while(s.find(nextNo) != s.end())
    //         {
    //             nextNo++;
    //             streakLen++;
    //         }
    //         maxStreak = max(maxStreak, streakLen);
    //     }
    // }
    // return maxStreak;

    // better approach because it will avoid redundant testing
    int maxStreak = 0;
    for(int i : s)
    {
        if(s.find(i-1) == s.end())
        {
            int nextNo = i+1;
            int streakLen = 1;
            while(s.find(nextNo) != s.end())
            {
                nextNo++;
                streakLen++;
            }
            maxStreak = max(maxStreak, streakLen);
        }
    }
    return maxStreak;
}
int main()
{
    int arr[] = {4, 0, -4, -2, 2, 5, 2, 0, -8, -8, -8, -8, -1, 7, 4, 5, 5, -4, 6, 6, -3};
    int n = sizeof(arr) / sizeof(int);

    cout << "Largest : " << findLargestSubseq(arr, n) << endl;
    return 0;
}
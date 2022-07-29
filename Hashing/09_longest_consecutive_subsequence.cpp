#include <iostream>
#include <unordered_map>
using namespace std;

int findLargestSeq(int arr[], int n)
{
    unordered_map<int, int> m;
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        // int arr[] = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
        int no = arr[i];
        if(m.find(no) != m.end())
        continue;

        if (m.count(no - 1) == 0 && m.count(no + 1) == 0)
        {
            m[no] = 1;
            largest = max(largest, 1);
        }
        else if (m.count(no - 1) && m.count(no + 1))
        {
            int len1 = m[no - 1];
            int len2 = m[no + 1];
            int streak = len1 + 1 + len2;
            m[no - len1] = streak;
            m[no + len2] = streak;
            m[no] = streak;
            largest = max(largest, streak);
        }
        else if (m.count(no - 1) && !m.count(no + 1))
        {
            int len = m[no - 1];
            m[no - len] = len + 1;
            m[no] = len + 1;
            largest = max(largest, len + 1);
        }
        else
        {
            int len = m[no + 1];
            m[no + len] = len + 1;
            m[no] = len + 1;
            largest = max(largest, len + 1);
        }
    }
    return largest;
}
int main()
{
    int arr[] = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    int n = sizeof(arr) / sizeof(int);

    cout << findLargestSeq(arr, n) << endl;
    return 0;
}
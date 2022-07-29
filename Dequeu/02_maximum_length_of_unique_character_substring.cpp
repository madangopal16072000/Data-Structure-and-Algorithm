#include<iostream>
#include<string.h>

using namespace std;
int main()
{
    char a[] = "abbacdeb";
    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;

    int visited[256] = {-1};

    visited[a[0]] = 0;
    for(int i=1; i<n; i++)
    {
        int last_occ = visited[a[i]];

        if(last_occ == -1 || i-current_len > last_occ)
        {
            current_len++;
        }
        else
        {
            max_len = max(current_len, max_len);

            current_len = i - last_occ;
        }
        visited[a[i]] = i;
    }
    max_len = max(current_len, max_len);

    cout << max_len << endl;
    return 0;
}
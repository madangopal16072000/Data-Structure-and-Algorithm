#include<iostream>
#include<numeric>
using namespace std;
bool isPossible(int A[], int n, int m, int min_pages)
{
    int sum_of_pages = 0;
    int student_count = 1;
    for(int i=0; i<n; i++)
    {
        if(sum_of_pages + A[i] > min_pages)
        {
            student_count++;
            sum_of_pages = A[i];
            if(student_count > m)
            return false;
        }
        else
        {
            sum_of_pages = A[i] + sum_of_pages;
        }
    }
    return true;
}
int max_pages_read(int A[], int n, int m)
{
    int s = A[n-1];
    int e = accumulate(A, A+n, 0);
    int min_pages;
    int ans = INT_MAX;
    while(s <= e)
    {
        min_pages = (s+e)/2;

        bool canbe = isPossible(A, n, m, min_pages);

        if(canbe)
        {
            ans = min(ans, min_pages);
            e = min_pages - 1;
        }
        else
        {
            s = min_pages + 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int *A = new int[n];
        for(int i=0; i<n; i++)
        cin >> A[i];
        cout << max_pages_read(A, n, m) << endl;
    }

    return 0;
}
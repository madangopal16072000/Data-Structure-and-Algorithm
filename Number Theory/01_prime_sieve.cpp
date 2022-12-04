#include <iostream>
#include<vector>
using namespace std;

void primeSieve(int A[], int n)
{
    // mark all odd number as prime

    for (int i = 3; i <= n; i += 2)
    {
        A[i] = 1;
    }

    for (int i = 3; i <= n; i += 2)
    {
        if (A[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
                A[j] = 0;
        }
    }

    A[2] = 1;
    A[0] = A[1] = 0;
}
int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;
    int *A = new int[n + 1];

    for (int i = 0; i <= n; i++)
        A[i] = 0;

    primeSieve(A, n);

    for (int i = 0; i <= n; i++)
    {
        if (A[i] == 1)
            cout << i << " ";
    }
    return 0;
}


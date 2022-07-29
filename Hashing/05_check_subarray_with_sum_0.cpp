#include<iostream>
#include<unordered_set>

using namespace std;

bool checkSum(int arr[], int n)
{
    int pre = 0;
    unordered_set<int> s;
    for(int i = 0; i<n; i++)
    {
        pre += arr[i];

        if(pre == 0 || s.find(pre) != s.end())
        return true;

        s.insert(pre);
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
    cin >> arr[i];

    if(checkSum(arr, n))
    cout << "True" << endl;
    else
    cout << "False" << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// given N points in a 2D catesian plane, How many right angled triagle are there such that perpendicular
// or base is parallel to X or Y axis

int noTriangle(vector<vector<int>> arr)
{
    unordered_map<int, int> fx;
    unordered_map<int, int> fy;
    for(int i = 0; i < arr.size(); i++)
    {
        fx[arr[i][0]]++;
        fy[arr[i][1]]++;
    }

    int count = 0;
    for(vector<int> row : arr)
    {
        if(fx[row[0]] >= 2 && fy[row[1]] >= 2)
        count = count + (fx[row[0]]-1)*(fy[row[1]]-1);
    }
    return count;
}
int main()
{
    vector<vector<int>> arr {{1,2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}};
    cout << noTriangle(arr);

}
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> inp;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        inp.push_back(d);
    }
    vector<int> csum;
    csum.push_back(0);
    for(int i = 0; i < n; i++)
    {
        csum.push_back(csum[i] + inp[i]);
    }
	int i;
    for(i = 0; i <= n; i++)
    {
        int j;
        for(j = i+1; j <= n; j++)
        {
            if(csum[j] - csum[i] == sum)
            {
                cout << "Yes" << endl;
                break;
            }
        }
        if(j != n+1)
        break;
    }
	if(i==n+1)
    cout << "No" << endl;
}

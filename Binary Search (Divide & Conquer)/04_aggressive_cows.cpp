#include<iostream>
#include<algorithm>
using namespace std;

bool CowPlaceCheck(int Stalls[], int N, int C, int min_speration)
{
    int count = 1;
    int lastCowPos = Stalls[0];
    for(int i=1; i<N; i++)
    {
        if(Stalls[i] - lastCowPos >= min_speration)
        {
            lastCowPos = Stalls[i];
            count++;
            if(count == C)
            return true;
        }
    }
    return false;
}
int main()
{
    int C, N;
    cout << "Enter no Stalls : ";
    cin >> N;
    cout << "Enter no Cows : ";
    cin >> C;
    int *Stalls = new int[N];
    cout << "Enter Stalls coordinates : " << endl;
    for(int i=0; i<N; i++)
    cin >> Stalls[i];

    int s = 0;
    sort(Stalls, Stalls + N);
    int e = Stalls[N-1] - Stalls[0];
    int ans = -1;
    int min_speration;
    while(s <= e)
    {
        min_speration = (s+e)/2;
        
        bool CowRakhPaye = CowPlaceCheck(Stalls, N, C, min_speration);
        if(CowRakhPaye)
        {
            ans = min_speration;
            s = min_speration + 1;
        }
        else
        e = min_speration - 1;

    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
class DataStream {
    int val, cnt;
    list<int> l;
public:
    DataStream(int value, int k) {
        val = value;
        cnt = k;
    }
    
    bool consec(int num) {
        
        l.push_back(num);

        if(l.size() < cnt)
        {
            return false;
        }
        else if(l.size() > cnt)
        {
            l.pop_front();
        }
        for(int x : l)
        {
            cout << x << endl;
            if(x != val)
                return false;
        }
        return true;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  DataStream ds(4, 3);

  ds.consec(4);
  ds.consec(4);
  ds.consec(4);
  ds.consec(3);
  return 0;
}
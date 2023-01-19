#include<bits/stdc++.h>
using namespace std;
class LFUCache {
    unordered_map<int, list<pair<int, int>>> freqList;
    unordered_map<int, list<pair<int, int>>::iterator> keynode;
    int size, freq, maxSize;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        size = 0;
        freq = 0;
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  
  return 0;
}
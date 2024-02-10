#include <bits/stdc++.h>
using namespace std;


class LFUCache {

    int sz;
    unordered_map<int, int> use_count;
    map<int, list<int>> m; 
    unordered_map<int, int> v;

    void use(int key){
        if(use_count.find(key) == use_count.end()){
            sz--;
            if(sz < 0){
                sz++;
                int remove = m.begin()->second.back();
                m.begin()->second.pop_back();

                if(m.begin()->second.empty())
                m.erase(m.begin());

                use_count.erase(remove);
                v.erase(remove);
            }
            use_count[key] = 1;
            m[1].push_front(key);
        }
        else{
            int cur_use_count = use_count[key];
            m[cur_use_count].erase(find(m[cur_use_count].begin(), m[cur_use_count].end(), key));
            use_count[key]++;
            m[cur_use_count+1].push_front(key);
        }
    }

public:
    LFUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(v.find(key) == v.end())
        return -1;
        else{
            use(key);
            return v[key];
        }
    }
    
    void put(int key, int value) {
        use(key);
        v[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    LFUCache lfu = LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    cout << lfu.get(1) << "\n";      // return 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    cout << lfu.get(2) << "\n";      // return -1 (not found)
    cout << lfu.get(3) << "\n";      // return 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    cout << lfu.get(1) << "\n";      // return -1 (not found)
    cout << lfu.get(3) << "\n";      // return 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    cout << lfu.get(4) << "\n";      // return 4
                    // cache=[4,3], cnt(4)=2, cnt(3)=3


    return 0;
}
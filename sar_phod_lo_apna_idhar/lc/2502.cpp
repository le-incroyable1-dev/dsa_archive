#include <bits/stdc++.h>
using namespace std;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Allocator {
public:

    vector<int> mem;
    int n;

    Allocator(int n) {
        mem.resize(n, -1);
        this->n = n;
    }
    
    int allocate(int size, int mID) {
        int s = 0;

        while(s < n){
            if(mem[s] != -1){
                ++s; continue;
            }

            int i = s;
            while(i < n && mem[i] == -1) ++i;
            int sz = i-s;
            if(sz >= size){
                for(int i = s; i < s+size; ++i) mem[i] = mID;
                return s;
            }
            else s = i;
        }

        return -1;
    }
    
    int free(int mID) {
        int c = 0;
        for(int i = 0; i < n; ++i) if(mem[i] == mID) mem[i] = -1, ++c;
        return c;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
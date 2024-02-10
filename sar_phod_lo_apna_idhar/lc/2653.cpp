#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& v, int k, int x) {
        
        int n = v.size();

        multiset<int> s;
        vector<int> beauty;
        for(int i = 0; i < k; ++i) if(v[i] < 0) s.insert(v[i]);
        
        if(s.size() < x) beauty.push_back(0);
        else{
            int c = x-1;
            while(c--) s.erase(s.begin());
            beauty.push_back(*s.begin());
        }

        int j = k;

        while(j < n){
            int rem = v[j-k];
            if(rem < 0) s.erase(rem);

            if(v[j] < 0) s.insert(v[j]);

            if(s.size() < x) beauty.push_back(0);
            else{
                while(s.size() > x) s.erase(s.begin());
                beauty.push_back(*s.begin());
            }
            ++j;
            continue;
        }
        
        return beauty;
    }
};

int main(){
    vector<int> v = {1,-1,-3,-2,3};
    int k = 3;
    int x = 2;

    Solution sol;
    sol.getSubarrayBeauty(v, k, x);
    return 0;
}
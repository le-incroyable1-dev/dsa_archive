#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        
        int n = v.size();
        sort(v.begin(), v.end());
        
        
        vector<int> mark(n, 0);
        
        int i = 0;
        int j = v.end() - lower_bound(v.begin(), v.end(), 2*v[0]);
        if(j == i) ++j;
        
        mark[i] = 1;
        mark[j] = 1;
        
        cout << i << " " << j << "\n";
        
        
        ++i;
        ++j;
        
        
        
        
        
        
        if(j == n) return 0;
        
        int ans = 1;
        
        while(i < n && j < n){
            
            while(i < n && mark[i]) ++i;
            if(i == n) break;
            while(j < n && 2*v[i] > v[j]) ++j;
            while(j < n && mark[j]) ++j;
            if(j == n) break;
            
            cout << i <<" " << j << "\n";
            
            mark[i] = 1;
            mark[j] = 1;
            
            ++ans;
            ++i;
            ++j;
            
            
        }
        
        
        ans *= 2;
        return ans;
        
        
    }
};
int main(){
    Solution sol;

    vector<int> v = {2,5,9,4};
    cout << sol.maxNumOfMarkedIndices(v);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> bit_dp;

    int solve(int k, int &n, int s, vector<int> &v){

        if(bit_dp[k][s] != -1) return bit_dp[k][s];
        int res = 0;
        for(int i = 0; i < n; ++i){
            int b1 = ((s>>i) & 1);
            
            if(b1 == 1) continue;
            
            for(int j = i+1; j < n; ++j){
        
                
                int b2 = ((s>>j) & 1);
                if(b1 == 1 || b2 == 1) continue;

                int el1 = v[i]; int el2 = v[j];
                int c_s = s;
                c_s |= (1<<i);
                c_s |= (1<<j);
                int c_res = (k * __gcd(el1, el2)) + solve(k+1, n, c_s, v);
        
                res = max(res, c_res);
            }
        }

        return bit_dp[k][s] = res;
    }

    int maxScore(vector<int>& v) {
        int n = v.size();
        //int m = n/2;
        bit_dp.resize(10, vector<int>((1<<(n+1)), -1));
        int res = solve(1, n, 0, v);
        return res;
        
    }
};
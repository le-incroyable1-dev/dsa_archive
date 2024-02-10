#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

class Solution {
public:
    int countPalindromes(string s) {
        
        int n = s.length();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(6, 0)));
        ll res = 0;

        for(int k = 1; k < 6; k += 2){
            for(int i = 0; i < n; ++i){
                for(int j = i; j < n; ++j){
                    if(k == 1){ dp[i][j][k] = (ll)j-(ll)i+1LL; continue; }
                    if(j-i+1 < k) continue;

                    (dp[i][j][k] += dp[i][j-1][k])%=mod;
                    if(s[i] == s[j]) (dp[i][j][k] += dp[i+1][j-1][k-2])%=mod;

                    continue;
                }
            }
        }

        res = dp[0][n-1][5]%mod;

        if(res > INT_MAX) return INT_MAX;
        else return (int)res;
    }
};

int main(){
    Solution sol;
    string s = "9999900000";
    cout << sol.countPalindromes(s);
    return 0;
}
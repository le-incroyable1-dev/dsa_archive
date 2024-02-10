#include <bits/stdc++.h>
using namespace std;

int isMatch(const string s, const string p) {
    
    int n = s.length();
    int m = p.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            if(j > 0 && p[j-1] == '*'){
                dp[i][j] = ((j-2 >= 0 && dp[i][j-2]) || (j-2 >= 0 && i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]));
            }
            else if(j > 0){
                dp[i][j] = (i > 0 && j > 0 && (s[i-1] == p[j-1] || p[j-1] == '.') && dp[i-1][j-1]); 
            }
            
        }
    }
    
    return dp[n][m];
}

int main(){
    cout << isMatch("aa", "aa");
    return 0;
}

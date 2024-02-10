#include <bits/stdc++.h>
using namespace std;


//O(n^2)
class Solution {

private:
    int lcs(string X, string Y, int m, int n,
            vector<vector<int> >& dp)
    {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                            lcs(X, Y, m - 1, n, dp));
    }


public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        string s1, s2;

        for(auto val : target)
        s1 += to_string(val);

        for(auto val : arr)
        s2 += to_string(val);

        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = m - lcs(s1, s2, m, n, dp);
        return ans;
    }
};
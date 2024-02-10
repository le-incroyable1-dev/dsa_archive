#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2) {

    if(s1.size() == 0)
    return s2.size();
    else if(s2.size() == 0)
    return s1.size();
    else if(s1 == s2)
    return 0;

    int minDist;

    if(s1[0] != s2[0])
    minDist = 1 + min(editDistance(s1.substr(1), s2), min(editDistance(s1, s2.substr(1)), editDistance(s1.substr(1), s2.substr(1))));
    else{
        minDist = editDistance(s1.substr(1), s2.substr(1));
    }

    return minDist;
}

int editDistanceDp(string s1, string s2) {

    if(s1.size() == 0)
    return s2.size();
    else if(s2.size() == 0)
    return s1.size();
    else if(s1 == s2)
    return 0;

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    int minDist;

    for(int i = 0; i <= m; ++i)
    dp[0][i] = i;

    for(int i = 0; i <= n; ++i)
    dp[i][0] = i;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(dp[i][j] == -1){
                if(s1[j-1] != s2[i-1])
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                else 
                dp[i][j] = dp[i-1][j-1];
            }
            else
            continue;
        }
    }

    minDist = dp[n][m];
    return minDist;
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    //cout << editDistance(s1, s2);
    cout << editDistanceDp(s1, s2);
}
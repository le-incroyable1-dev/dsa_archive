#include <bits/stdc++.h>
using namespace std;


int helper(vector<pair<int, int>> &v, int m, int k, int n, vector<vector<vector<int>>> &dp){
    int sz = v.size();

    if(dp[m][k][n] != -1)
    return dp[m][k][n];

    if(m == 0)
    return 0;

    if(n == 0)
    return 0;

    int dontbuy = 0;
    int buy = 0;
    int buyd = 0;

    dontbuy = 0 + helper(v, m, k, n-1, dp);
    int index = sz - n;
    
    if(m >= v[index].first){
        buy = v[index].second + helper(v, m-v[index].first, k, n-1, dp);
    }

    if(k > 0 && m >= floor(v[index].first/2)){
        buyd = v[index].second + helper(v, m-floor(v[index].first/2), k-1, n-1, dp);
    }

    int ans = max(dontbuy, max(buy, buyd));
    dp[m][k][n] = ans;
    return ans;
}

int getMaximumNutrition(int m, vector<int> &price, vector<int> &nutrition, int k){
    int n = price.size();
    vector<pair<int, int>> v;

    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(k+1, vector<int>(n+1, -1)));

    for(int i= 0; i < n; ++i){
        v.push_back(make_pair(price[i], nutrition[i]));
    }

    int ans = helper(v, m, k, n, dp);
    return ans;
}

int main(){

    vector<int> price = {2, 4,5};
    vector<int> nutrition = {20,17,15};
    cout << getMaximumNutrition(4, price, nutrition, 1);
    return 0;
}
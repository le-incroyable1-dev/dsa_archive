#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    
    unordered_map<ll, ll> freq;
    unordered_map<ll, ll> m;
    
    ll str = 1;
    vector<ll> dp;
    ll streak(vector<ll> &v, ll i){
    
        ll n = v.size();
        ll res = 0;
        
        if(dp[i] != -1) return dp[i];
        
        if(i == n) return dp[i] = 0;
        
        ll r1 = 1;
        ll r2 = streak(v, i+1);
        
        ll cur = v[i];
        //ll f = freq[cur];
        
        ll nxt = cur*cur;
        if(m.find(nxt) != m.end()) r1 += streak(v, m[nxt]);
        
        //cout << i << "\n" << r1 << " " << r2 << "\n\n";
        
        str = max(r1, str);
        str = max(r2, str);
        
        return dp[i] = r1;
    }
    
    int longestSquareStreak(vector<int>& nums) {
        
        for(auto val : nums) freq[val]++;
        
        vector<ll> v;
        for(auto p : freq) v.push_back(p.first);
        sort(v.begin(), v.end());
    
        ll n = v.size();
        for(ll i = 0; i < n; ++i) m[v[i]] = i;
        
        dp.resize(n+2, -1);
        streak(v, 0);
        
        if(str >= 2) return (int)str;
        else return -1;
        
    }
};
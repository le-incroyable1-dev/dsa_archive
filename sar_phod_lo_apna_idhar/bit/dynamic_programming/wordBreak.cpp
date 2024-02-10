#include <bits/stdc++.h>
using namespace std;



unordered_set<string> ss;

bool isPossible(string &s, int i, int n, vector<int> &dp){

    if(dp[i] != -1) return dp[i];
    if(i == n) return dp[i] = true;

    bool res = false;
    string cur = "";
    for(int j = i; j < n; ++j){
        cur += s[j];
        if(ss.find(cur) != ss.end()) res |= isPossible(s, i+1, n, dp);
    }

    return dp[i] = res;
}

int wordBreak(string s, vector<string> &v) {

    int n = s.length();
    for(auto str : v) ss.insert(str);
    vector<int> dp(n+1, -1);

    bool ans = isPossible(s, 0, n, dp);
    return (int)ans;
}


int main(){

    string s = "abababababaaaabaabbbabbbabbababbb";
    vector<string> v = {"abbbabaa", "baabaaaab", "babaaaaaba", "b", "b", "bbaaaab", "aaabbb", "aabbbbbab", "abbb", "abaa", "aaababaab", "aabbabaa", "bab", "bbbbaabbb"};

    cout << wordBreak(s, v) << "\n";
    return 0;
}
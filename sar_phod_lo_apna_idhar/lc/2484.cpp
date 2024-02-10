#include <bits/stdc++.h>
using namespace std;


class Solution {
public:


    int solve(string &s, int si, int ei, int len){

        int ans = 0;

        if(ei < si)
        return 0;

        if(ei == si){
            return (int)(len==1);
        }

        if(len == 1){
            return (ei-si+1);
        }

        
        else if(len == 0)
        return 1;

        if(ei-si+1 < len)
        return 0;

        int n = s.length();

        for(int i = si; i <= ei; ++i){
            for(int j = si+1; j <= ei; ++j){
                if(s[i] == s[j]){
                    ans += solve(s, i+1, j-1, len-2);
                }
            }
        }

        return ans;

    }

    int countPalindromes(string s) {

        int n = s.length();
        int res = 0;
        for(int len = n; len >= 5; len--){
            res += solve(s, 0 , n-1, len);
            cout << res << "\n";
        }

        return res;

    }
};

int main(){

    Solution sol;

    string s = "0000000";

    cout << sol.countPalindromes(s) << endl;


    return 0;
}
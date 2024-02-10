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
    int maxJump(vector<int>& s) {
        
        int n = s.size();
        
        if(n == 2) return (s[1] - s[0]);

        int jump = 0;

        for(int i = 2; i < n; i += 2) jump = max(jump, s[i] - s[i-2]);
        for(int i = 3; i < n; i += 2) jump = max(jump, s[i] - s[i-2]);

        return jump;
    }
};
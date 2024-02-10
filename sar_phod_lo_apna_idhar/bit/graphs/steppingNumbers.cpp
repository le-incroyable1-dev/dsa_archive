#include <bits/stdc++.h>
using namespace std;


void solve(int a, int b, int num, vector<int> &ans){

    if(num < a){
        if(num%10 > 0){
            int nxt = num*10 + (num%10 - 1);
            solve(a, b, nxt, ans);
        }

        if(num%10 < 9){
            int nxt = num*10 + (num%10 + 1);
            solve(a, b, nxt, ans);
        }
    }
    else if(num >= a && num <= b){

        ans.push_back(num);

        if(num%10 > 0){
            int nxt = num*10 + (num%10 - 1);
            solve(a, b, nxt, ans);
        }

        if(num%10 < 9){
            int nxt = num*10 + (num%10 + 1);
            solve(a, b, nxt, ans);
        }

    }
    else{
        return;
    }

}

vector<int> stepnum(int a, int b) {

    vector<int> ans;

    for(int i = 0; i < 10; ++i)
    solve(a, b, i, ans);
    
    set<int> s;
    
    vector<int> res;
    
    for(auto val : ans){
        if(s.find(val) == s.end())
        res.push_back(val);
        
        s.insert(val);
    }
    
    sort(res.begin(), res.end());

    return res;

}
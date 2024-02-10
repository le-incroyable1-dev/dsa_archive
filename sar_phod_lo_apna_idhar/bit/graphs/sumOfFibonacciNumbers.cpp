#include <bits/stdc++.h>
using namespace std;


//greedy strategy works, O(n) solution
//refer : https://en.wikipedia.org/wiki/Zeckendorf%27s_theorem

int fibsum(int A){

    vector<long long> v;
    v.push_back(1); v.push_back(1);    
        
    while(v.back() < INT_MAX){       
        int n = v.size();        
        long long t =  v[n-1] + v[n-2];         
        v.push_back(t);        
    } 
            
    int ans = 0;    
    int k = A;

    while(k!=0){         
        while(v.back() > k){             
            v.pop_back();         
        }                  
        k -= v.back();         
        ans++;     
    }     
    
    return ans;
}
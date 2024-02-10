#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        int ele;
        for(int i = 0; i < n; ++i) cin >> ele, v.push_back(ele);

        vector<int> pre(n, 0);
        pre[0] = v[0];
        for(int i = 1; i < n; ++i) pre[i] = pre[i-1] + v[i];


        vector<int> suf(n, 0);
        suf[n-1] = v[n-1];
        for(int i = n-2; i >= 0; i--) suf[i] = suf[i+1] + v[i]; 


        for(auto val : pre) cout << val << "\n";
        cout << "\n";
        for(auto val : suf) cout << val << "\n";

        continue;
    }
    
    return 0;
}
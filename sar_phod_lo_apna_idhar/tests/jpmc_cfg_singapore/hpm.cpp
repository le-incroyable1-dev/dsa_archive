#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int k){
    int ans = 0;

    int n = v.size();
    int len = 0;
    for(int i = 0; i < n; ++i){
        if(i == n-1){
            len++;
            if(len-k+1 > 0)
            ans += len-k+1;
        }
        else{
            if(v[i] < v[i+1]){
                len++;
            }
            else{
                len++;
                if(len-k+1 > 0)
                ans += len-k+1;
                len = 0;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> v = {5,3,5,7,8};
    cout << solve(v, 3) << "\n";
    return 0;
}
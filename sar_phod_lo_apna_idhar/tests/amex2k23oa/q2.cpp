#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int solution(vector<int> &a){
    int n = a.size();

    int i = 1;
    int j = 3;

    ll left_min = LLONG_MAX;
    ll res = LLONG_MAX;

    while(j < n){
        left_min = min(left_min, (ll)a[i]);
        ll cur_res = a[j] + left_min;
        res = min(res, cur_res);
        ++j;
        ++i;
    }
    
    if(res > INT_MAX) return INT_MAX;
    else return (int)res;
}


int main(){
    return 0;
}
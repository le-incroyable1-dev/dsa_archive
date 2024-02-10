#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

//incomplete
void populate(vector<ll> &store, int n){

    queue<pair<ll, ll>> q;
    q.push({1, 1});
    store[1] = 1;

    while(!q.empty()){

        if(store[0] != -1)
        break;

        pair<ll, ll> p = q.front(); q.pop();
        ll num = p.first;

        ll num1 = num*10;
        ll num2 = num*10 + 1;

        ll rem1 = num1%n;
        ll rem2 = num2%n;

        if(store[rem1] == -1){
            store[rem1] = num1;
            q.push({rem1, rem1});
        }

        if(store[rem2] == -1){
            store[rem2] = num2;
            q.push({rem2, rem2});
        }

        if(rem1 == 0 || rem2 == 0)
        break;

    }

    return;
    
}

string multiple(int n) {

    if(n == 1)
    return "1";

    vector<ll> store(n, -1);
    populate(store, n);
    ll res = store[0];
    string ans = to_string(res);
    return ans;
}


int main(){

    int n;
    cin >> n;
    cout << multiple(n) << "\n";
    return 0;
}
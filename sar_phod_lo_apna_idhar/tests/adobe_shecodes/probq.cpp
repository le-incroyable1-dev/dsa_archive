#include <bits/stdc++.h>
using namespace std;




void solve(vector<int> &b, vector<int> &j){

    map<int, int> mb;
    map<int, int> mj;

    for(auto val : b)
    mb[val]++;

    for(auto val : j)
    mj[val]++;

    for(auto p : mb){
        int face = p.first;
        int ct = p.second;


    }



}

int main(){

    int t; cin >> t;

    while(t--){
        vector<int> b, j;
        int ele;

        for(int i = 0; i < 6; ++i){
            cin >> ele;
            b.push_back(ele);
        }

        for(int i = 0; i < 6; ++i){
            cin >> ele;
            j.push_back(ele);
        }

        solve(b, j);
    }


    return 0;
}
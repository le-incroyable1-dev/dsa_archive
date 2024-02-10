#include <bits/stdc++.h>
//typedef long long ll;
using namespace std;

int solve(int n, int a[], int b[]){

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        v.push_back(make_pair(a[i], b[i]));
    }

    sort(v.begin(), v.end());

    int ct = 0;

    for(int i = 0; i < n-1; i++){
        if(v.at(i).first < v.at(i+1).first && v.at(i).second < v.at(i+1).second){
            ct++;
        }
    }

    return n-ct;

}
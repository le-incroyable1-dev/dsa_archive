#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first > p2.first;
}

void func(vector<int> v){
    unordered_map<int, int> freq;
    unordered_map<int, int> m;

    int n = v.size();

    for(auto u : v) freq[u]++;
    for(int i = 0; i < n; ++i){
        if(m.find(v[i]) == m.end()) m[v[i]] = i;
    }

    vector<pair<int, int>> vp;

    for(auto p : freq){
        int val = p.first;
        int count = p.second;

        vp.emplace_back(count, m[val]);
    }

    sort(vp.begin(), vp.end(), cmp);

    for(auto p : vp){
        int count = p.first;
        int val = v[p.second];

        while(count--) cout << val << " ";
    }

    return;
}

int main(){
    vector<int> v = {3,6,3,6,3,6};
    func(v);
    return 0;
}
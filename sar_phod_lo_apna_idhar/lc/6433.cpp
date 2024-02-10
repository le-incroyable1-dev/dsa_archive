#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> *g;
    vector<int> vis;

    void dfs(int i, int &nv){

        ++nv;
        vis[i] = 1;

        for(auto v : g[i]){
            if(vis[i] != 0) continue;
            dfs(v, nv);
        }

        return;
    }

    void dfs_c(int i, int& nv, bool &c){
        
        vis[i] = 2;
        if(c == false) return;
        if(g[i].size() != nv-1){ c = false; return; }

        for(auto v : g[i]){
            if(vis[i] == 2) continue;
            dfs_c(v, nv, c);
        }

        return;
    }

    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<int> gr[n];
        for(auto v : e) gr[v[0]].push_back(v[1]), gr[v[1]].push_back(v[0]);
        g = gr;
        vis.resize(n, 0);
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            int cur_v = 0;
            dfs(i, cur_v);

            bool c = true;
            dfs_c(i, cur_v, c);

            if(c) ++res;
        }

        return res;

        
    }
};
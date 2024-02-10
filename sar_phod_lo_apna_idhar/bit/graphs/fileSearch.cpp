#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool> &vis, int ind){
    vis[ind] = true;

    for(auto i : adj[ind]){
        if(!vis[i]){
            dfs(adj, vis, i);
        }
    }

    return;
}

int breakRecords(int n, vector<vector<int> > &mat) {
    vector<vector<int>> adj(n+1);

    for(auto i : mat){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<bool> vis(n+1, false);

    int ans = 0;
    for(int i = 1; i<=n; i++){
        // if(adj[i].size() == 0) ans += 1;

        if(!vis[i]){
            ans++;
            dfs(adj, vis, i);
        
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> mat = {
        {8,4},
        {3,1},
        {5,4},
        {5,8},
        {3,4},
        {3,7},
        {8,5},
        {5,8},
        {3,4}
    };

    cout << breakRecords(8, mat);
    return 0;
}
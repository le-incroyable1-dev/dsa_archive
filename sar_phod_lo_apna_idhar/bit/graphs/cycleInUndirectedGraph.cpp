#include <bits/stdc++.h>
using namespace std;

bool processDFSTree(set<int> s, vector<vector<int>> &adj, vector<bool> &vis, int cur, int parent){

    if(s.find(cur) != s.end())
    return true;

    s.insert(cur);
    vis[cur] = true;

    bool res = false;

    for(auto val : adj[cur]){
        
        if(val != parent)
        res |= processDFSTree(s, adj, vis, val, cur);    
        if(res)
        break;
    }

    s.clear();
    return res;

}

int solve(int n, vector<vector<int> > &v) {

    vector<vector<int>> adj(n);

    for(auto vec : v){
        adj[vec[0]-1].push_back(vec[1]-1);
        adj[vec[1]-1].push_back(vec[0]-1);
    }

    vector<bool> vis(n, false);

    for(int i = 0;i < n; ++i){
        if(!vis[i]){
            set<int> s;
            if(processDFSTree(s, adj, vis, i, -1))
            return 1;
        }
    }

    return 0;
}


int main(){

    vector<vector<int>> v = {{1,2}};
    cout << solve(2, v) << endl;
    return 0;
}

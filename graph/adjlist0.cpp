#include <bits/stdc++.h>
using namespace std;


vector<int> getPathDfs(vector<int> adj[], int v, int e, int sv, int ev, bool vis[]){
    
    if(vis[sv])
        return {};
    
    if(sv == ev)
        return {ev};
    
    vector<int> revpath;

    vis[sv] = true;
    
    for(auto val : adj[sv]){
        
        if(vis[val])
            continue;
        
        revpath = getPathDfs(adj, v, e, val, ev, vis);
        if(revpath.size() > 0){
            //revpath = getPathDfs(adj, v, e, val, ev, vis);
            revpath.push_back(sv);
            return revpath;
        }
    }
    
    return {};
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    if(v == 0)
        return 0;
    
 
    //adjacency list
    vector<int> adj[v];
    
    for(int i = 0; i < v; ++i){
        adj[i] = {};
    }
    
    for(int i = 0; i < e; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int v1, v2;
    cin >> v1 >>  v2;

    
    vector<int> path;
    bool vis[v];
    memset(vis, false, v);
    
    for(auto val : getPathDfs(adj, v, e, v1, v2, vis)){
        cout << val << " ";
        //path.push_back(val);
    }
    
    // reverse(path.begin(), path.end());
    
    // for(auto val : path)
    //     cout << val << " ";

    return 0;
}

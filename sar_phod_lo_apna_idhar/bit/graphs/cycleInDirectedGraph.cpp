#include <bits/stdc++.h>
using namespace std;


bool processDFSTree(set<int> s, vector<vector<int>> &adj, vector<bool> &vis, int cur){

    if(s.find(cur) != s.end())
    return true;

    s.insert(cur);
    vis[cur] = true;

    bool res = false;

    for(auto val : adj[cur]){
        res |= processDFSTree(s, adj, vis, val);
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
    }

    vector<bool> vis(n, false);

    for(int i = 0;i < n; ++i){
        if(!vis[i]){
            set<int> s;
            if(processDFSTree(s, adj, vis, i))
            return 1;
        }
    }

    return 0;
}

int main(){

    vector<vector<int>> v = {{1,2}, {2, 3}, {3, 4}, {4, 5}};
    cout << solve(5, v) << endl;
    return 0;
}

//  A = 5
//  B = [  [1, 2] 
//         [4, 1] 
//         [2, 4] 
//         [3, 4] 
//         [5, 2] 
//         [1, 3] ]
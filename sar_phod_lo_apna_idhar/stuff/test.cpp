

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int n, vector<int> *adj, vector<vector<int>> &dist, vector<int> &ans, int node, vector<bool> &vis){

        vis[node] = true;
        int res = 0;

        dist[node][node] = 0;

        for(auto val : adj[node]){

            dist[node][val] = 1;
            dist[val][node] = 1;

            if(!vis[node])
            solve(n, adj, dist, ans, val, vis);

            res += 1;
            for(auto nxt : adj[val]){
                dist[node][nxt] = 1 + dist[val][nxt];
                dist[nxt][node] = dist[node][nxt];

                res += dist[node][nxt];
            }

        }

        ans[node] = res;
        return;

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<int> adj[n+1];
        vector<vector<int>> dist(n+1, vector<int>(n+1, 0));
        vector<bool> vis(n+1, false);

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> ans(n+1, -1);
        solve(n, adj, dist, ans, 0, vis);

        for(int i = 0; i < n; ++i){

            cout << i << "\n";
            for(int j = 0; j < n; ++j){
                cout << j << " " << dist[i][j] << "\n";
            }

            cout << "\n";
        }

        return ans;
    }
};
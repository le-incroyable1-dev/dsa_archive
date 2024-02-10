#include <bits/stdc++.h>
using namespace std;

int dxdy[4][2] = {{0,-1}, {-1, 0}, {0, 1}, {1, 0}};

bool isValid(int i, int j, int n, int m){

    if(i >= 0 && i < n && j >= 0 && j < m)
    return true;
    else
    return false;
}


void dfs(vector<vector<char>> &g, vector<vector<bool>> &vis, int i, int j){
    if(vis[i][j])
    return;
    
    int n = g.size();
    int m = g[0].size();
    
    vis[i][j] = true;
    
    for(int k = 0; k < 4; ++k){
        int x = i + dxdy[k][0];
        int y = j + dxdy[k][1];
        
        if(isValid(x, y, n, m) && g[x][y] == 'O')
        dfs(g, vis, x, y);
    }
    
    return;
}


void solve(vector<vector<char> > &g) {
    
    int n = g.size();
    int m = g[0].size();
    vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == 'O' && !vis[i][j] && (i == n-1 || i == 0 || j == m-1 || j == 0))
            dfs(g, vis, i, j);
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!vis[i][j] && g[i][j] == 'O')
            g[i][j] = 'X';
        }
    }
    
    return;
}

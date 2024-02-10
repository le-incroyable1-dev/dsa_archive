#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &g, int v, bool *vis, int sv){
    
    if(vis[sv])
        return;
    
    
    vis[sv] = true;
    cout << sv << " ";
    
    for(int i = 0; i < v; ++i){
        if(g[sv][i] == 1 && !vis[i]){
            dfs(g, v, vis, i);
        }
    }
    
    return;
    
}

void printConnected(vector<vector<int>> &g, int v, int e){
    
    bool vis[v];
    
    int nxt = 0;
    
    while(nxt < v){
        
        dfs(g, v, vis, nxt);
        
        cout << endl;
        
        while(vis[nxt] && nxt < v)
            nxt++;
        
    }
    
    return;
    
}

int main() {
    // Write your code here
    
    int v, e;
    cin >>  v >> e;
    
    vector<vector<int>> g(v, vector<int>(v, 0));
    
    for(int i = 0; i < e; ++i){
        int a, b;

        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    
    printConnected(g, v, e);
    
    return 0;
    
}
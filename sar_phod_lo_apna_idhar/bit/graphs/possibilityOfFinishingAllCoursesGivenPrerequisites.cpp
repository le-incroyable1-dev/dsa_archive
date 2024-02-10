#include <bits/stdc++.h>
using namespace std;

void helper(int A, vector<vector<bool>> &graph, vector<bool> &vis, vector<bool> &done, int cur){

    vis[cur] = true;
    bool possible = true;
    
    for(int i = 1; i <= A; ++i){
        if(graph[i][cur] && !done[i])
        possible = false;
    }
    
    if(possible){
        done[cur] = true;
        for(int i = 1;i <= A; ++i){
            if(graph[cur][i])
            helper(A, graph, vis, done, i);
        }
    }
    
    return;
    
}

int solve(int A, vector<int> &B, vector<int> &C) {
    
    vector<vector<bool>> graph(A+1, vector<bool>(A+1, false));
    int n = B.size();
    
    for(int i = 0; i < n; ++i){
        graph[B[i]][C[i]] = true;
    }
    
    vector<bool> vis(A+1, false);
    vector<bool> done(A+1, false);
    vis[0] = true;
    done[0] = true;
    
    int j = 1;
    
    while(j <= A){
        while(j <= A && vis[j])
        ++j;
        
        if(j > A)
        break;
        
        helper(A, graph, vis, done, j);
        
        // cout << j << endl;
        // for(auto val : done)
        // cout << (int)val << " ";
        
        // cout << endl;
        
        continue;
    }
    
    
    //cout << endl;
    
    for(auto val : done)
    if(val != true)
    return 0;
    
    return 1;
    
}
